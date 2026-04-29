// logind.c

// 访问次数显示.
// 一次ban多个ip的支持( such as ban 166.111 or ban 162.105.11 )
// (注意封162.105.11?.*是ban 162.105.11%s,不需要再写下面的)
// 并且将访问控制存入文件
// 计数器,lazy_write_back,提高性能同时减少文件坏的可能.
// 新的登录认证方式
// 自动清理过期用户
// 防止恶意不断连线

// by YEUNG
// 由原来ES2 LOGIND改写而来

// by dongsw
// 改写模式结构

// 增加了两种选择天赋的方式，随机和自主。
// 最大连线时间设置为五分钟。
// 去除了真实性命、住址等暂时无用的设置
// by Dongsw 2003

#define NO_PLAYER 0
#define NO_NEW_PLAYER 0
// #define AVOID_LOGIN_FLUSH

#define LOGIN_ACCESS "/data/access.deny"
#define LOGIN_TIME "/data/login.num"
#define LOGIN_TIME_BAK "/data/loginbak.num"
#define SAVE_EXTENSION ".o"
#define SAVE_BAK ".bak.o"

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <localtime.h>

inherit F_DBASE;
//inherit F_MAIL;

int wait_for_login;


string FROM_DATE;
int cur_num;
string *week_name = ({
        "星期日","星期一","星期二","星期三","星期四","星期五","周末星期六",
});

private void random_gift(object ob, object user);
void get_taxes(object user);
void ask_usr(string flag,object user);
int ban_ip(string ip);
int wiz_lock_level = WIZ_LOCK_LEVEL;

string *banned_id = ({
        "you", "yours", "she", "her", "him", "his","mine",
        "one","other","this","that","there","here","combatd",
        "root","master","halfgod","admin","annihilator",
        "fuckyou","fuck","tmd","shit","guest","none","cancel",
});

string *banned_name = ({
        "你", "您", "我", "他", "她", "它", "它",
        "道可道","流星雨","晓风残月","道全",
});

string *banned_site = ({
});

#ifdef AVOID_LOGIN_FLUSH
// 记录不同的IP连线状态
// 5分钟清空一次，此间隙内一个IP只允许连线5次
// 连续3次超过此限制，即认为是不断连线，暂时禁止其访问 10 分钟

mapping ip_status = allocate_mapping(300);
mapping ip_denined;
#endif
string *start_loc = ({
        "/d/snow/temple",
        "/d/xizang/inn1",
        "/d/cloud/tearoom",
        "/d/jingcheng/jiuguan",
        "/d/yueyang/kedian",
        "/d/suzhou/kezhan",
  });
string *v_gifts = ({"cor","cps","int","lea","dex","bln","con","str"});
string *v_gifts_name = ({"胆识","定力","悟性","统御","身法","平衡","体质","力量"});

private void get_id(string arg, object ob);
private void confirm_license(string yn, object ob);
private void read_license(string yn, object ob);
//object make_body(object ob);
varargs object make_body(object ob,string body);
private void init_new_player(object ob,object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
private void get_new_id(string id,object ob);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int select_gifts(object ob,object user);
int ask_user(string flag,object ob,object user,int total);
int ask_user_set(string flag, object ob, object user, int sel, int total);
int confirm_user(string flag,object ob,object user);

void read_banned_sites()
{
        string file;
        file = read_file(LOGIN_ACCESS);
        if( !stringp(file) ) return;
        banned_site = explode(file, "\n");
}

void write_banned_sites()
{
        string str;
        int k,j;

        str = "";
        k = sizeof(banned_site);
        for(j=0;j<k;j++)
                str += banned_site[j]+"\n";
        write_file(LOGIN_ACCESS,str,1);
}

void ban_site(string site)
{
        banned_site -= ({site});
        banned_site += ({site});
        write_banned_sites();
}

void unban_site(string site)
{
        banned_site -= ({site});
        write_banned_sites();
}

void flush_bak_cache()
{
        remove_call_out("flush_bak_cache");
        write_file(LOGIN_TIME_BAK,sprintf("%d %s",cur_num,FROM_DATE),1);
}

void flush_cache()
{
        remove_call_out("flush_cache");
        call_out("flush_cache",300);
        call_out("flush_bak_cache",60);
        write_file(LOGIN_TIME,sprintf("%d %s",cur_num,FROM_DATE),1);
#ifdef AVOID_LOGIN_FLUSH
        ip_status = ([]);
#endif
}
#ifdef AVOID_LOGIN_FLUSH
mapping query_ip_status()
{
        return ip_status;
}

mapping query_ip_denined()
{
        return ip_denined;
}
#endif
void create()
{
        mixed tmp,*c_time;
        string err;

        seteuid(getuid());
        set("channel_id", "连线精灵");

#ifdef CLEAN_EXPIRED_USER
        wait_for_login = 1;
        call_out("cleanup_user",5);
#endif
        read_banned_sites();
        call_out("flush_cache",300);

        //读取计数器文件
        err = catch(tmp = read_file(LOGIN_TIME));
        if( !err && stringp(tmp) && !catch(sscanf(tmp,"%d %s",cur_num,FROM_DATE)) && intp(cur_num) && stringp(FROM_DATE) )
        {
                FROM_DATE = replace_string(FROM_DATE,"\n","");
                FROM_DATE = replace_string(FROM_DATE,"\r","");
        }
        //计数文件有错
        else
        {
                //用备份替换
                seteuid(ROOT_UID);
                write("计数器文件错误,使用备份文件.\n");
                rm(LOGIN_TIME);
                cp(LOGIN_TIME_BAK,LOGIN_TIME);
                err = catch(tmp = read_file(LOGIN_TIME));
                if( !err && stringp(tmp) && !catch(sscanf(tmp,"%d %s",cur_num,FROM_DATE)) && intp(cur_num) && stringp(FROM_DATE) )
                {
                        FROM_DATE = replace_string(FROM_DATE,"\n","");
                        FROM_DATE = replace_string(FROM_DATE,"\r","");
                }
                //备份都坏了
                else
                {
                        write("计数器文件错误,重新生成.\n");
                        c_time = localtime(time());
                        FROM_DATE = "公元"+chinese_number(c_time[LT_YEAR])+"年"+chinese_number(c_time[LT_MON]+1)+"月"+chinese_number(c_time[LT_MDAY])+"日";
                        cur_num = 0;
                        write("起始日期为"+FROM_DATE+"\n");
                        write_file(LOGIN_TIME,sprintf("%d %s",cur_num,FROM_DATE),1);
                }
        }

}


void logon(object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;

        if( !objectp(ob) || !ob )
        {
                log_file("get_ip_bug",ctime(time())+"Cannot get IP from a null object.\n");
                return;
        }

#ifdef AVOID_LOGIN_FLUSH

        if( mapp(ip_denined) )
        {
                if( ip_denined[query_ip_number(ob)] > time() )
                {
                        write(YEL"\n对不起，您的地址在短时间内多次连接本站，给本站带来了过大冲击.\n");
                        write("请您等候 5 分钟后再连接本站。注意请不要在此期间反复尝试，因为\n");
                        write("这样只会导致系统认为您继续反复连接从而延长您的等待时间。再见。\n"NOR);
                        destruct(ob);
                        return;
                }
                else
                        map_delete(ip_denined,query_ip_number(ob));
        }

        if((++ip_status[query_ip_number(ob)])>10)
        {
                //列入黑名单(5分钟)
                if( !mapp(ip_denined) ) ip_denined = allocate_mapping(50);
                ip_denined[query_ip_number(ob)] = time()+300;
        }

#endif

//      cat(WELCOME);
        WELCOME_D->show_welcome();
//      cat(PLAYER_NEWS);
        UPTIME_CMD->main();
        cur_num ++;
//        printf("您是从"+FROM_DATE+"起的第"+chinese_number(cur_num)+"位访问者。\n");
        printf("纵横天下II自开站来共有"+chinese_number(cur_num)+"人访问了本站。\n\n");
        if( wait_for_login && query_ip_number(ob) != ADMIN_IP)
        {
                write(HIY"系统正在维护中,请稍候5分钟之后再登录.\n");
                write("请不要反复连接本站,避免过大的网络冲击.谢谢.\n"NOR);
                destruct(ob);
        }

          usr = filter_array(objects(), (: userp($1) :));
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( wiz_level(usr[i]) )
                {
                        if (! usr[i]->query("env/invisibility")) wiz_cnt++;
                }
                else ppl_cnt++;
        }
/*          printf(YEL"目前共有 %s 位巫师、%s 位玩家在线上，以及 %s 位使用者尝试连线中。\n"NOR,
                  chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );*/
          printf(YEL"目前共有[%s]位巫师、[%s]位玩家在线上，以及[%s]位使用者尝试连线中。\n"NOR,
                  chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );

        write("您的英文名字(请输入"HIY"new"NOR" 注册新用户)：");
        input_to( (: get_id :), ob );
}

private void get_id(string arg, object ob)
{
        object ppl;

        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("您的英文名字(请输入"HIY"new"NOR" 注册新用户)：");
                input_to("get_id", ob);
                return;
        }


#ifdef MAX_USERS
        if( wizhood(arg)=="(player)" && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
                // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
                        destruct(ob);
                        return;
                }
        }
#endif

//#ifdef ENABLE_BAN_SITE
        if( wizhood(arg)=="(player)" ) {
                int i;
                string ip;

                ip = query_ip_number(ob);
                for(i=0; i<sizeof(banned_site); i++)
                        if( (ip == banned_site[i])
                        ||      sscanf(ip, banned_site[i])) {
                                write("对不起，您的 IP Address 目前被列为拒绝连线地区。\n");
                                destruct(ob);
                                return;
                        }
        }
//#endif

        if( wiz_level(arg) < wiz_lock_level ) {
                write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
                        + " 以上的人才能连线。\n");
                destruct(ob);
                return;
        }

        if( arg=="new" ) {
                write("\n您的英文名字：");
                input_to("get_new_id", ob);
                return;
        }

        //不许普通玩家进入
        if( wizhood(arg)=="(player)" && NO_PLAYER)
        {
                write("开发站目前不对玩家开放.\n");
                destruct(ob);
                return;
        }

        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" ) {
                //不许GUEST进入
                write(YEL"\n对不起,本站不开放访客参观,请注册后再进入本站。\n"NOR);
                write("您的英文名字(请输入"HIY"new"NOR" 注册新用户)：");
                input_to("get_id", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
                if( ob->restore() ) {
                        write("请输入登陆密码：");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write(YEL"\n您的人物储存挡出了一些问题，请与 "+ADMIN_EMAIL+" 联系。\n"NOR);
                destruct(ob);
                return;
        }
        write("对不起,没有这个用户帐号.\n");
        ob->add_temp("login_retry",1);
        if( ob->query_temp("login_retry") > MAX_LOGIN_RETRY)
        {
                write(HIY"您已经多次登录失败,请仔细检查您的帐号和密码,如果有疑问,\n");
                write("请您与 "+ADMIN_EMAIL+" 联系.\n"NOR);
                destruct(ob);
                return;
        }
        write("您的英文名字(请输入"HIY"new"NOR" 注册新用户)：");
        input_to("get_id", ob);
        return;
}

private void get_new_id(string id,object ob)
{
        if( id == "new" )
        {
                write("\n对不起，不允许使用这个名字。\n");
                write("\n您的英文名字：");
                input_to("get_new_id", ob);
                return;
        }

        if( !check_legal_id(id)) {
                write("\n您的英文名字：");
                input_to("get_new_id", ob);
                return;
        }

        //不许普通玩家进入
        if( wizhood(id)=="(player)" && NO_NEW_PLAYER)
        {
                write("开发站目前不对玩家开放.\n");
                destruct(ob);
                return;
        }

        ob->set("id",id);


        if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
        {
                write("\n对不起，这个用户已经存在了。\n");
                write("\n您的英文名字：");
                input_to("get_new_id", ob);
                return;
        }
        ob->set_temp("createing",1);
        //注册新用户

        write( 
YEL"\n ────────【创建新人物】────────\n\n\n"NOR

"            请输入您所创建角色的姓名，\n"
"       此姓名将代表您在此游戏中走过一生，\n"
"       请慎重抉择，请不要起一些造成他人\n"
"       困扰的名字，此类角色一律被杀档。\n\n"

    YEL"└──────────────────────┘\n\n"NOR
        );
        write("您的中文名字：");
        input_to("get_name", ob);
        return;
}

private void get_passwd(string pass, object ob)
{
        string my_pass;
        string my_ad_pass;
        
        object user;

        write("\n");
        my_pass = ob->query("password");
        my_ad_pass = ob->query("ad_password");
        if( ! stringp(my_pass) || crypt(pass, my_pass) != my_pass ) {
                if (! stringp(my_ad_pass) || crypt(pass, my_ad_pass) != my_ad_pass)
                {
                        write("密码错误！\n\n");
                        ob->add_temp("login_retry",1);
                        if( ob->query_temp("login_retry") > MAX_LOGIN_RETRY)
                        {
                                write(HIY"您已经多次登录失败,请仔细检查您的帐号和密码,如果有疑问,\n");
                                write("请您与 "+ADMIN_EMAIL+" 联系.\n"NOR);
                                destruct(ob);
                                return;
                        }
                        else
                        write("您的英文名字(请输入"HIY"new"NOR" 注册新用户)：");
                        input_to( (: get_id :), ob );                   
                        return;
                }
        }

        if (! stringp(my_ad_pass))
        {
                write(YEL "您的人物尚没有设定管理密码，请设定管理密码。\n\n" NOR);

                write("请设定的管理密码：");
                input_to("reset_ad_password", 1, ob);
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() )
                {
                        if( ob->query("reset_gift_accquired") )
                        {
                                init_new_player(ob,user);
                        }
                        else
                        {
                                log_file( "USAGE", sprintf("%s logged in from %s (%s)\n", (string)user->query("id"),query_ip_name(ob), ctime(time()) ) );
                                enter_world(ob, user);
                        }
                        return;
                } else {
                        destruct(user);
                }
        }
        write("您的人物储存挡出了一些问题,请通知巫师处理。\n");
        destruct( ob);

}

private void reset_ad_password(string pass, object ob)
{
        string my_pass;
        write("\n");

        if (strlen(pass) < 6)
        {
                write(YEL"管理密码的长度不能小于六位。\n"NOR);
                write("\n您的管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        my_pass = ob->query("password");
        if (stringp(my_pass) && crypt(pass, my_pass) == my_pass)
        {
                write(YEL "管理密码和登陆密码不能相同。\n\n" NOR);
                write("您的管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        ob->set_temp("ad_password", crypt(pass, 0));
        write("请确认您的管理密码：");
        input_to("confirm_reset_ad_password", 1, ob);
}

private void confirm_reset_ad_password(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query_temp("ad_password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write(YEL"您两次输入的管理密码不同。\n"NOR);
                write("\n您的管理密码：");
                input_to("reset_ad_password", 1, ob);
                return;
        }

        ob->set("ad_password", old_pass);
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，欢迎下次再来。\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "有人从别处( " + query_ip_number(ob)
                        + " )连线取代您所控制的人物。\n");
                log_file( "USAGE", sprintf("%s is replaced by %s (%s)\n", (string)user->query("id"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }
        if( !objectp(environment(user)) )
        {
                user->move("/d/snow/inn");
                user->set("startroom","/d/snow/inn");
                tell_object(user,"您的档案似乎出了点问题,需要从这里连线开始.\n");
        }


        reconnect(ob, user);
}

private void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("您的中文名字：");
                input_to("get_name", ob);
                return;
        }

        //printf("%O\n", ob);
        ob->set("name", arg);
        write(YEL
        "\n ────────【邮箱地址】────────\n\n"NOR
        
        "\n            请输入您的电子邮件地址，您\n"
        "       的密码将被发到这个信箱，这也是维护\n"
        "       您的帐号（比如密码丢失）的唯一凭证。\n\n"
     HIR"              请一定不要填错！\n"NOR
        
        YEL"└──────────────────────┘\n\n"NOR
        );
        write("您的电子邮件地址：");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        if( strsrch(email,"@") == -1 || strsrch(email,".") == -1 )
        {
                write(YEL"\n您的电子邮件地址格式不正确。请用例如 dongsiw@sohu.com 的格式。\n\n"NOR);
                write("您的电子邮件地址：");
                input_to("get_email",  ob);
                return;
        }
        ob->set("email",email);
        write("\n请确认您的电子邮件地址：");
        input_to("confirm_email", 1, ob);
}

private void confirm_email(string email, object ob)
{
        object user;

        if( ob->query("email") != email )
        {
                write(YEL"\n您两次输入的电子邮件地址不同。\n\n"NOR);
                write("您的电子邮件地址：");
                input_to("get_email", 1, ob);
                return;
        }
        write(YEL
        "\n ────────【管理密码】────────\n\n"NOR
        
        "\n            请设定您的管理密码，此密码\n"
        "       为管理密码，此密码也可以登陆游戏，当\n"
        "       您需要使用例如：自杀、放弃武功的功能\n"
        "       时需要输入管理密码，此密码颇为重要，请\n"
        "       不要频繁使用！                    \n\n"    
     HIR"              请不要忘记密码！\n"NOR
        
        YEL"└──────────────────────┘\n"NOR
        );        

        write("\n您的管理密码：");       

        input_to("new_ad_password", ob, user);

}

private void new_ad_password(string pass, object ob)
{
        write("\n");
        if (strlen(pass) < 6)
        {
                write(YEL"管理密码的长度不能小于六位。\n"NOR);
                write("\n您的管理密码：");
                input_to("new_ad_password", 1, ob);
                return;
        }
        ob->set_temp("ad_password", crypt(pass, 0));
        write("请确认您的管理密码：");
        input_to("confirm_ad_password", 1, ob);
}

private void confirm_ad_password(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query_temp("ad_password");
        if (crypt(pass, old_pass) != old_pass)
        {
                write(YEL"您两次输入的管理密码不同。\n"NOR);
                write("\n您的管理密码：");
                input_to("new_ad_password", 1, ob);
                return;
        }

        ob->set("ad_password", old_pass);
        write(YEL
        "\n ────────【登陆密码】────────\n\n"NOR
        
        "\n            请设定您的登陆密码，此密码\n"
        "       为登陆密码，在您登陆游戏的时候使用，\n"
        "       最好设定为您容易记忆的密码。\n\n"
     HIR"              请不要忘记密码！\n"NOR
        
        YEL"└──────────────────────┘\n"NOR
        );        
        write("\n您的登陆密码：");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
        string ad_pass;
        
        write("\n");
        if( strlen(pass)<5 ) {
                write(YEL"登陆密码的长度不能小于五位。\n"NOR);
                write("\n您的登陆密码：");
                input_to("new_password", 1, ob);
                return;
        }
        
        if (stringp(ad_pass = ob->query("ad_password")) &&
            crypt(pass, ad_pass) == ad_pass)
        {
                write(YEL "登陆密码和管理密码不能相同。\n\n" NOR);
                write("您的登陆密码：");
                input_to("new_password", 1, ob);
                return;
        }
        
        ob->set("password", crypt(pass,0) );
        write("请确认您的登陆密码：");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        object user;

        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write(YEL"您两次输入的登陆密码不同。\n"NOR);
                write("\n您的登陆密码：");
                input_to("new_password", 1, ob);
                return;
        }

        // If you want do race stuff, ask player to choose one here, then you can
        // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;

        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender",ob,user);
}

private void get_gender(string gender, object ob, object user)
{

        if( gender=="" ) {
                write("\n您要扮演男性(m)的角色或女性(f)的角色？");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else {

                write("对不起，您只能选择男性(m)或女性(f)的角色：");
                input_to("get_gender", ob, user);
                return;
        }

        ob->set("born/time",ctime(time()));
        ob->set("born/address",query_ip_name(ob));
        ob->set("privilage",1);
        user->set("privilage",1);

        init_new_player(ob,user);
}

varargs object make_body(object ob,string body)
{
        string err;
        object user;

        if( stringp(body) )
        {
                if( geteuid(previous_object())!= ROOT_UID ) return 0;
                user = new(body);
        }
        else
                if( raw_wiz_level(ob->query("id")) )
                        user = new(WIZUSER_OB);
                else

                        user = new(ob->query("body"));

        if(!user) {
                write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

private void init_new_player(object ob,object user)
{
        int i,j;
        string *h_gifts = ({"per","kar","fav","spi","elo","msc","wil","vis"});

        if( !ob->query("reset_gift_accquired") )
        {
                user->set("title", "普通百姓");
                user->set("birthday", time() );
                user->set("potential", 99);
                user->set("shen",0);
                user->set("MagicNum", 1+random(50000));
                CHAR_D->setup_char(user);
                user->set("food", user->max_food_capacity() );
                user->set("water", user->max_water_capacity() );
                user->set("channels", ({ "chat","zh","new","rumor" }) );
                user->set("env/no_accept", "YES");
                user->set("eff_kee",100);
                user->set("eff_gin",100);
                user->set("eff_sen",100);
                user->set("kee",100);
                user->set("gin",100);
                user->set("sen",100);
                if( user->query("gender") == "女性" )
                {
                        user->add("potential",200);
                        user->add("combat_exp",500);
                }
        }
        //生成隐含天赋
        j = sizeof(h_gifts);
        for(i=0;i<j;i++)
                user->set(h_gifts[i],5+random(26));

        //普通人都是右手偏好
        if( random(5) )
                user->set("fav",20+random(11));
        //灵性不能太低
        user->set("spi", 10 + random(21) );

        //让用户挑选显性天赋
        j = sizeof(v_gifts);
        for(i=0;i<j;i++)
                user->set(v_gifts[i],10);

        write(YEL
        "\n ─────────────【天赋选择】─────────────\n\n"NOR
        
        "\n         这个游戏中总共有以下各种天赋,不同的天赋对人物\n"
          "     的未来会有不同的影响,而且这些影响常常是终身的,请根据\n"
          "     您的喜好和对未来发展的计划来仔细调整天赋.\n"
        "
    cor(胆识) 攻击速度和特殊场景,门派有要求
    cps(定力) 影响对方攻击,自己防御,门派有要求
    int(悟性) 影响学习速度，领悟速度，还有特定其他用途
    lea(统御) 影响团队的整体攻防,阵法的效果和组阵速度,政治性
              人物的主要天赋之一
    dex(身法) 影响防御和移动速度，有些高深的功夫必须
    bln(平衡) 人物的平衡能力，一些比较高深的功夫需要平衡能力很强，
              并且影响防御能力
    con(体质) 影响精气神数量,从昏迷中恢复速度,抗击打能力,人物的
              最终寿命
    str(力量) 负重能力,杀伤力,特殊技能要求\n\n"
    HIR"    天赋各有用处，并无某项最优，后天不可更改，请慎重选择！\n"NOR
        YEL"└───────────────────────────────┘\n\n"NOR
        );        

        write(" 请您选择设置自身天赋的方式( 1：随机设置 / 2：自主分配 )");
        input_to("check_setgift_way", ob, user);

        //select_gifts(ob,user);
        //random_gift(ob, user);
}

int check_setgift_way(string arg, object ob, object user)
{
        if ( arg == "1" )
        {
                write(YEL"\n 您选择了随机分配天赋的方式。\n"NOR);
                random_gift(ob, user);
                return 1;
        }
        else if( arg == "2")
        {
                write(YEL"\n 您选择了自主分配天赋的方式。\n"NOR);
                select_gifts(ob,user);
                return 1;
        }
        else
        {
                write(" 请您选择设置自身天赋的方式(1:随机设置/2:自主分配)：");
                input_to("check_setgift_way", ob, user);
        }
}
private void random_gift(object ob, object user)
{
        mapping my = ([]);
        int i;
        int tmpcor, tmpcps, tmpint, tmplea, tmpdex, tmpbln, tmpcon, tmpstr;
        tmpcor = tmpcps = tmpint = tmplea = tmpdex = tmpbln = tmpcon = tmpstr = 10;
        
        for (i = 0; i < 100; i++) {
                switch (random(8)) {
                case 0: tmpcor++; break;
                case 1: tmpcps++; break;
                case 2: tmpint++; break;
                case 3: tmplea++; break;
                case 4: tmpdex++; break;
                case 5: tmpbln++; break;
                case 6: tmpcon++; break;
                case 7: tmpstr++; break;
                }
        }

        if (tmpcor <= 30) my["cor"] = tmpcor; else my["cor"] = 30;
        if (tmpcps <= 30) my["cps"] = tmpcps; else my["cps"] = 30;
        if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
        if (tmplea <= 30) my["lea"] = tmplea; else my["lea"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
        if (tmpbln <= 30) my["bln"] = tmpbln; else my["bln"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;

        my["str"] = MAX_TOTAL_GIFTS - my["cor"] - my["cps"] - my["int"] - my["lea"] - my["dex"] - my["bln"] - my["con"];
        
        if( my["str"] > 30)
        {
                random_gift(ob, user);
                return;
        }
        
        user->set("cor",my["cor"]);
        user->set("cps",my["cps"]);
        user->set("int",my["int"]);
        user->set("lea",my["lea"]);
        user->set("dex",my["dex"]);
        user->set("bln",my["bln"]);
        user->set("con",my["con"]);
        user->set("str",my["str"]);

        write("\n ────────────────────────────────\n");
        printf(GRN" 1：胆识：[%d]  2：定力：[%d]  3：悟性：[%d]  4：统御：[%d]\n",
              user->query("cor"),user->query("cps"),user->query("int"),user->query("lea"));
        printf(" 5：身法：[%d]  6：平衡：[%d]  7：体质：[%d]  8：力量：[%d]\n"NOR,
              user->query("dex"),user->query("bln"),user->query("con"),user->query("str"));
        write(" ────────────────────────────────\n");
        write("\n 您对以上的天赋满意吗？(y/n):");
        input_to("check_random_gift", ob, user);
        
}

int check_random_gift(string arg, object ob, object user)
{
        if ( arg == "n" || arg == "N")
        {
                random_gift(ob, user);
                return 1;
        }
        else if( arg == "y" || arg == "Y")
        {
                write("\n\n");
                enter_world(ob,user,0);
                ob->delete("reset_gift_accquired");
                return 0;
        }
        else
        {
                write(" 您对以上的天赋满意吗？(y/n):");
                input_to("check_random_gift", ob, user);
        }
}

        
int select_gifts(object ob,object user)
{
        int total,j;


        j = sizeof(v_gifts);
        total = 0;
        while(j--)
                total += (user->query(v_gifts[j]));
        total = MAX_TOTAL_GIFTS - total;
        write("\n ────────────────────────────────\n");
        printf(GRN" 1：胆识：[%d]  2：定力：[%d]  3：悟性：[%d]  4：统御：[%d]\n",
              user->query("cor"),user->query("cps"),user->query("int"),user->query("lea"));
        printf(" 5：身法：[%d]  6：平衡：[%d]  7：体质：[%d]  8：力量：[%d]\n"NOR,
              user->query("dex"),user->query("bln"),user->query("con"),user->query("str"));
        write(" ────────────────────────────────\n");
        total != 0 ? printf(YEL" 您还有 %d 点天赋剩余。\n\n"NOR,total)
        : write(YEL" 您没有剩余的天赋点了。(0 结束)\n\n"NOR);

        //write("请分配剩余点数(1/8代表第一项天赋+8,1/-4代表第一项天赋-4,\n2代表第二项天赋,如此类推,0表示结束)\n");
        write(" 请选择天赋：(1,2,3...)");
        input_to("ask_user",ob,user,total);

}

int ask_user(string flag,object ob,object user,int total)
{
        int sel;

        if( !flag || !stringp(flag) || strlen(flag) < 1 )
        {
                select_gifts(ob,user);
                return 1;
        }
        if( flag == "0" )
        {
                if( total < 0 )
                {
                        input_to("confirm_gifts",ob,user);
                        return 1;
                }
                if( total > 0 )
                {
                        write(HIR"\n 天赋点还有剩余！请继续分配。\n"NOR);
                        select_gifts(ob,user);
                        return 1;
                }
                write("\n 您对以上的天赋满意吗？(y/n)");
                input_to("confirm_gifts",ob,user);
                return 1;
        }

        if( sscanf(flag, "%d", sel) != 1 || sel<1 || sel>8 )
        {
                write(HIR"\n 输入不正确！\n"NOR);
                select_gifts(ob,user);
                return 1;
        }

        write(" 请设定" + v_gifts_name[sel-1] + "的数值：(10-30)");
        input_to("ask_user_set", ob, user, sel, total);
        return 1;
}

int ask_user_set(string flag, object ob, object user, int sel, int total)
{
        int num;
        
        if( sscanf(flag, "%d", num) != 1 )
        {
                write(HIR"\n 输入不正确！\n"NOR);
                select_gifts(ob,user);
                return 1;
        }
        if( num - (int)user->query(v_gifts[sel-1]) > total)
        {
                write(YEL"\n 对不起,您没有这么多点数可以分配了。\n"NOR);
                select_gifts(ob,user);
                return 1;
        }
        
        if( num < 10 || num > 30 )
        {
                write(YEL"\n 对不起,天赋的限制范围是(10-30)。\n"NOR);
                select_gifts(ob,user);
                return 1;
        }

        write("\n 您将" + v_gifts_name[sel-1] + "的数值设定为"+ HIW + num + NOR + " 点。\n");
        user->set(v_gifts[sel-1], num);
        select_gifts(ob, user);
}


int confirm_gifts(string flag,object ob,object user)
{
        if( stringp(flag) && (flag[0] == 'y' || flag[0] == 'Y') )
        {
                write("\n\n");
                enter_world(ob,user,0);
                ob->delete("reset_gift_accquired");
                return 0;
        }
        else
                select_gifts(ob,user);
}

varargs void enter_world(object ob, object user, int silent)
{
        object cloth;
        string startroom;
        int block_time;

        //cat(PLAYER_NEWS);

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);
        write(REF"\n\n");

       block_time = user->query("block_time");
       if( block_time>time() && !wiz_level(user) && !raw_wiz_level(user))
        {
                write(sprintf("对不起，您暂时被禁止连线进入,请等%d分钟以后再来。\n",(block_time-time())/60+1));
                destruct(user);
                destruct(ob);
                return;
        }
        else user->delete("block_time");

        write("目前权限：" + wizhood(user) + "\n");
        user->setup();

        if( user->query("MagicNum") == 0 )
          user->set("MagicNum",1+random(50000));
        // In case of new player, we save them here right aftre setup
        // compeleted.
        user->save();
        ob->save();

        cloth = new("/obj/cloth/cloth");
        cloth->move(user);
        cloth->wear();

        user->add("login_time",1);

        if( !silent ) {
                REPLACE_D->replace_ansi("/adm/etc/license");
                write("\n");
//              if(wizardp(user)) cat("/adm/etc/wiz_news");
                if( user->query("login_time") <= 1)
                tell_object(user,WHT"一阵眩晕过后，你慢慢的睁开眼睛，发现自己身处在一个完全陌生的世界中......\n\n"NOR);
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
                        //startroom = start_loc[random(sizeof(start_loc))];
                        startroom = "/d/newb/jitan";

                if( find_object(startroom) || !catch(startroom->foo()) )
                        user->move(startroom);
                else {
                          startroom = start_loc[random(sizeof(start_loc))];
                        user->move(startroom);
                        user->set("startroom", startroom);
                }
                tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                        ({user}));
        }
        if (user->query("login_time") > 1)
        {
                tell_object(user,"这是您第"+chinese_number((int)user->query("login_time"))+"次访问本站。\n");
        }
        else
        {
                tell_object(user,HIG"\n你刚刚定了定神，就听见一个男孩的声音：“" + user->name() + "，欢迎来到纵横天下的世界！”\n\n"NOR);
        }
        
        FINANCE_D->get_taxes(user);
        if( ob->query("new_mail") ) {
                write( BLINK + GRN + "\n有您的信！请检查您的信箱...\n\n" + NOR);
                ob->delete("new_mail");
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)由%s连线进入。", user->name(), (string)user->query("id"), query_ip_name(user)) );
        UPDATE_D->check_user(user);
        NEWS_D->read_news(user);
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent && (! wizardp(user) || ! user->query("env/invisibility"))) {

                tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)由%s重新连线进入。", user->query("name"), (string)user->query("id"),  query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);

          if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
                write(YEL"\n对不起，您的英文名字必须是 3 到 8 个英文字母。\n"NOR);
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write(YEL"\n对不起，您的英文名字只能用英文字母。\n"NOR);
                        return 0;
                }
        if( member_array(id, banned_id)!=-1 ) {
                write(YEL"\n对不起，本游戏不允许使用这种英文名字。\n"NOR);
                return 0;
        }

        return 1;
}

int check_legal_name(string name)
{
        int cp, i;

        // FluffOS: str[i] returns Unicode codepoint of i-th character (not byte).
        // Valid Chinese characters are in CJK Unified (U+4E00-U+9FFF = 19968-40959)
        // and CJK Extension A (U+3400-U+4DBF = 13312-19967).

        for (i = 0; ; i++) {
                cp = name[i];

                // End of string
                if (cp == 0) break;

                // Reject control characters
                if (cp <= ' ') {
                        write(YEL"\n对不起，您的中文名字不能用控制字元。\n\n"NOR);
                        return 0;
                }

                // Check CJK range (U+3400-U+9FFF)
                if (cp < 13312 || cp > 40959) {
                        write(YEL"\n对不起，请您用「中文」取名字。\n\n"NOR);
                        return 0;
                }

                // Limit to 4 characters max
                if (i >= 4) {
                        write(YEL"\n对不起，您的中文名字必须是 2 到 4 个中文字。\n\n"NOR);
                        return 0;
                }
        }

        if (i < 2) {
                write(YEL"\n对不起，您的中文名字必须是 2 到 4 个中文字。\n\n"NOR);
                return 0;
        }

        if (member_array(name, banned_name) != -1) {
                write(YEL"\n对不起，这种名字会造成其他人的困扰。\n\n"NOR);
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}

int ban_ip(string ip)
{
        string site;

        if (ip == "query"){
                if(!sizeof(banned_site)) write("现在没有被拒绝访问的IP。\n");
                else write(implode(banned_site, "\n") + "\n");
        }
        else if (sscanf(ip, "+ %s", site) == 1) {
                        banned_site -= ({site});
                        banned_site += ({site});
                }
        else if (sscanf(ip, "- %s", site) == 1)
                banned_site -= ({site});
        else return 0;
        return 1;
}

int user_expired(string name)
{
        object ob;
        mapping my;
        int days;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return 0;

        my = ob->query_entire_dbase();

        //printf("\n%s(%s)--",my["name"],name);
        //未上线天数
        days = (time()-(int)my["last_on"])/86400;

        switch (my["privilage"])
        {
                // guest
                case -1 : if( days > LIFE4GUEST ){destruct(ob);return 1;}break;
                // user
                case 1 :
                case 2 :
                case 3 : if( days > LIFE4USER ){destruct(ob);return 1;}break;
                // 聊天帐号,巫师等不过期
        }
        destruct(ob);
        return 0;
}

private int do_purge_dummy_file(string name)
{

        reset_eval_cost();

        cp(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION,"/databak/login/" + name + SAVE_EXTENSION);
        cp(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION,"/databak/user/"  + name + SAVE_EXTENSION);

        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + ".bak" + SAVE_EXTENSION);

        //删除信件
        rm( "/data/mail/"+name[0..0]+"/"+name+".o" );

        return 1;
}

int cleanup_user()
{
        int i, j, ppl_cnt, count;
        string *dir,*ppls,name;

        //开始清理
        wait_for_login = 1;
        seteuid(getuid());
        message("system", YEL"\n*** 整理玩家储存档中，请稍候.... ***\n"NOR, users());
        write("处理中：");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(dir[i]);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        //忽略*.bak.o
                        if( sscanf(ppls[j], "%s.bak.o", name)==1 ) continue;
                        if( sscanf(ppls[j], "%s.o", name)==1 )
                                if( (string)SECURITY_D->get_status(name)!="(player)" || raw_wiz_level(name))
                                        continue;
                        if( user_expired(name) ) {
                                do_purge_dummy_file(name);
                                count ++;
                        }
                }
        }
//      write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
//      write( count + " 个过期使用者被清除掉了。\n");
//      write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
        log_file("static/PURGE", sprintf("[%s] LOGIN_D cleaned up %d characters expired.\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15],  count, ppl_cnt - count));
        wait_for_login = 0;
        return 1;
}




