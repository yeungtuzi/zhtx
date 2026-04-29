#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit F_FOOD;
inherit HAMMER;
inherit F_CLEAN_UP;

void setup()
{}

string status_color(int current, int max);

void init()
{
        add_action("do_eat", "eat");
        add_action("do_full", "full");
        add_action("do_grow", "grow");
        add_action("do_ii", "ii");
        add_action("do_hhp", "hp");
        add_action("do_ccall", "ccall");
        add_action("do_cclone", "cclone");
        add_action("do_ssnoop", "ssnoop");
        add_action("do_cd", "ccd");
        add_action("do_lls", "lls");
        add_action("do_more", "mmore");
        add_action("do_sscore", "sscore");
        add_action("do_ggoto", "ggoto");
        add_action("do_wwhere", "wwhere");
        add_action("do_sskills", "sskills");
        add_action("do_ddetect", "ddetect");
        add_action("do_eedit", "eedit");
        add_action("do_uupdate", "uupdate");
}

void create()
{
        seteuid(getuid());
        set_name("烤鸡腿", ({ "fried chicken leg", "chicken", "leg" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枝烤得香喷喷鸡腿，你还犹豫什麽？分泌胃液吧。\n");
                set("unit", "根");
                set("value", 30);
                set("food_supply",-1);
                set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}

int do_eat(string arg)
{
       if( !this_object()->id(arg) ) return 0;
       message_vision("$N拿起烤鸡腿咬了几口。\n", this_player());
        this_player()->add("food", 40);
       return 1;
}

int do_full()
{
        object me = this_player();

                       me->set("gin", (int)me->query("max_gin"));
                                   me->set("eff_gin", (int)me->query("max_gin"));
                                  me->set("kee", (int)me->query("max_kee"));
                                  me->set("eff_kee", (int)me->query("max_kee"));
                                  me->set("sen", (int)me->query("max_sen"));
                                  me->set("eff_sen", (int)me->query("max_sen"));
                                  me->set("atman", 2*(int)me->query("max_atman"));
                                  me->set("force", 2*(int)me->query("max_force"));
       me->set("mana", 2*(int)me->query("max_mana"));
       me->set("food",me->max_food_capacity());
           me->set("water",me->max_water_capacity());
    //    tell_object(me,HIW"你感觉浑身一阵轻松!\n"NOR);
                     return 1;
}

int do_grow()
{
        int questoktime;
        object me = this_player();
        questoktime=me->query("quest_ok");
        if(questoktime<10) me->set("quest_ok",10);
        me->add("faith",3+random(4));
                        me->add("potential",300);
                me->add("combat_exp",1800+random(200));
                me->add("nquestok",1);
                //tell_object(me,HIY"你突然感觉灵光一闪，似乎自身修为有了显著提高！\n"NOR);
                return notify_fail("什麽？\n");
}

int do_ii(string arg)
{
        int i;
        object *inv,*inv_weapon,*inv_armor,*inv_magic,*inv_medicine,*inv_other,
               *inv_money,*inv_food,*inv_water,ob,me;
        string str;

                me=this_player();
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));

        if( !ob ) ob = me;

        inv = all_inventory(ob);
        inv_weapon = filter_array(inv, (: $1->query("weapon_prop")&& !$1->query("adv_props")&& !$1->query("money_id") :));
        inv_armor = filter_array(inv,(: $1->query("armor_type")&& !$1->query("adv_props") :));
        inv_magic = filter_array(inv,(: $1->query("adv_props") :));
        inv_medicine = filter_array(inv,(: $1->query("medicine") :));
          inv_money = filter_array(inv,(: $1->query("money_id") :));
        inv_food = filter_array(inv,(: sizeof($1->query("food_supply"))>0 :));
        inv_water = filter_array(inv,(: sizeof($1->query("max_liquid"))>0 :));
        inv_other = inv - inv_weapon - inv_armor - inv_magic - inv_medicine - inv_money
                    - inv_food - inv_water;
        if( !sizeof(inv) ) {
                write((ob==me)? "目前你身上没有任何东西。\n"
                        : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }
        str  = HIY"  [总共：%s件]  [负重：%d%%]\n"NOR;
        str += HIY"────────────────\n"NOR;
        if (sizeof(inv_weapon)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_armor)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_magic)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_medicine)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_money)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_food)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_water)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_other)>0)str += "%s\n";
        else str+="%s";
        printf(str,
                chinese_number((int)sizeof(inv)),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
                implode(map_array(inv_weapon, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_armor, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_magic, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_medicine, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_money, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_food, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_water, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_other, "inventory_desc", this_object()), "\n"),

                );

        return 1;
}


string inventory_desc(object ob)
{
        string str;
        str=MAG"[杂]"NOR;
        if (ob->query("weapon_prop")) str=HIR"[武]"NOR;
        if (ob->query("armor_type")) str=HIW"[防]"NOR;
        if (ob->query("adv_props")) str=HIM"[魔]"NOR;
        if (ob->query("medicine")) str=HIG"[药]"NOR;
          if (ob->query("money_id")) str=HIY"[钱]"NOR;
        if (ob->query("food_supply")) str=HIC"[食]"NOR;
        if (ob->query("max_liquid")) str=HIC"[水]"NOR;

        return sprintf(HIY"  "NOR+str+"%s%s",
                ob->query("embedded")? HIR "√" NOR:
                ob->query("equipped")? HIC "□" NOR:"  ",
                ob->short()
        );

}

int do_hhp(string arg)
{
        object ob,me;
        mapping my;

     //   seteuid(getuid(me));

        me=this_player();
        if(!arg) ob = me;
        else {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
        }

        my = ob->query_entire_dbase();

    printf(" 精  ： %s%4d/ %4d %s(%3d%%)" NOR "    灵力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],      my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
                my["atman_factor"] );
    printf(" 气  ： %s%4d/ %4d %s(%3d%%)" NOR "    内力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
                my["force_factor"] );
    printf(" 神  ： %s%4d/ %4d %s(%3d%%)" NOR "    法力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
                my["mana_factor"] );
    printf(" 食物： %s%4d/ %4d      " NOR "     潜能： %s%d\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIY,
        (int)ob->query("potential") - (int)ob->query("learned_points"));
    printf(" 饮水： %s%4d/ %4d      " NOR "     武学： %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM,
        my["combat_exp"] );
    printf("                         " NOR "    商业： %s%d\n" NOR,
        HIM,
        my["magic_exp"] );
if(!query_snoop(me))
    printf(HIC" ------ 纵横天下II ------ " NOR "   政治:  %s%d\n" NOR,
        HIM,
        my["tactic_exp"] );
 else
   printf(HIC" ------ 纵横天下II ------" NOR "   政治:  %s%d\n" NOR,
                HIM,
        my["tactic_exp"] );

        return 1;
}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int do_ccall(string arg)
{
        string objname, func, param, euid;
        object obj, me;
        mixed *args, result;
        int i;
        me=this_player();

        if( arg ) {

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
        } else
                return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");

        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname=="me") obj = me;
        if(!obj) return notify_fail("找不到指定的物件。\n");

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                object ob_arg;

                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                if( args[i]=="me") { args[i] = me; continue; }
                if( (ob_arg = present(args[i], me))
                ||      (ob_arg = present(args[i], environment(me))) )
                        args[i] = ob_arg;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func,
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}


int do_cclone(string file)
{
        object obj, me;
        string err, msg;

        me=this_player();

        if (!file) file = me->query_temp("cwf");
        if (!file)
                return notify_fail("你要复制什麽物件？\n");

        file = resolve_path(me->query_temp("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set_temp("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("没有这个档案(" + file + ")。\n");

        if( !find_object(file) ) {
                        call_other(file, "???");
             if( !find_object(file) )  return 1;
                        }

        obj = new(file);
        if (!obj) {
                 return 1;
        }

        if( !obj->is_character()
        && obj->move(me) ) {
                return 1;
        }
        if( obj->move(environment(me)) ) {
                return 1;
        }

        destruct(obj);
        return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

int do_ssnoop(string arg)
{
        object ob, me;
        me=this_player();

        if( !arg ) {
                if( objectp(ob = query_snooping(me)) )
                        write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
                return 1;
        } else if( arg=="none" ) {
                snoop(me);
                write("Ok.\n");
                return 1;
        }

        ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if(!ob) return notify_fail("没有这个人。\n");
        if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
        snoop(me, ob);
        write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");

        return 1;
}

int do_cd(string arg)
{
        string dir;
        object me=this_player();

        if( !arg )
                arg = user_path(me->query("id"));
        dir = resolve_path(me->query_temp("cwd"), arg);
        if(file_size(dir)!=-2) return notify_fail("没有这个目录。\n");

        if(dir[strlen(dir)-1]!='/') dir += "/";
        me->set_temp("cwd", dir);
        write(dir + "\n");
        return 1;
}

int do_lls(string arg)
{
        int mark_loaded;
        int i, j, w, col;
        string dir;
        mixed *file;
        object me=this_player();

        dir = resolve_path(me->query_temp("cwd"), arg);
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
                else
                return notify_fail("没有这个目录。\n");
        }

        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        write("目录：" + dir + "\n");
        col = 70 / (w+6);
        if (sizeof(file))
                for(i=0, j = sizeof(file); i<j; i++)
                        printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
                                file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
                                ((i+1)%col)?"  ":"\n");
        else write("    没有任何档案。\n");
        write("\n");

        return 1;
}

void mmore(string arg, string *text, int line)
{
        int i,j,num;
        string cmd;
        if(sscanf(arg, "%s %d", cmd, num)==2) line+=num;
        else cmd=arg;
        if(line<-22) return;

        switch(cmd) {
                case "f":
                case "":
                        for(i=line + 23; line<sizeof(text) && line<i; line++)
                                write(text[line] + "\n");
                        if( line>=sizeof(text) ) return;
                        break;
                case "q":
                        return;
        }
        printf("== 未完继续 " HIY "%d / %d" NOR " == (ENTER 或 f 继续下一页，q 离开, + 可加行号.",
                line,sizeof(text));
        input_to("mmore", text, line);
}

void start_mmore(string msg)
{
        mmore("", explode(msg, "\n"), 0);
}


int do_more(string arg)
{
        string file;
        object ob;
        object me=this_player();

        seteuid(geteuid(me));
        if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
        file = resolve_path(me->query_temp("cwd"), arg);
        if( file_size(file) < 0 ) {
                ob = present(arg, me);
                if( !ob ) ob = present(arg, environment(me));
                if( !ob ) return notify_fail("没有这个档案。\n");
                file = base_name(ob) + ".c";
        }
        start_mmore( read_file(file));
        return 1;
}

int get_dp(object ob,int type)
{
        string attack_skill,skill_type,parry_type;
        object weapon;
        int attack_points, dodge_points, parry_points;
        int zhenqi;
        mapping prepare;

        if( !ob ) return 0;

        prepare = ob->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if ( sizeof(prepare) == 0) attack_skill = "unarmed";
          else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
            else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[ob->query_temp("action_flag")];

        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = attack_skill;
                parry_type = attack_skill;
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, parry_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

        switch(type)
        {
                case 0: return attack_points;
                case 1: return parry_points;
                case 2: return dodge_points;
                case 3: return dodge_points+parry_points;
        }
        return 0;
}


int do_sscore(string arg)
{
        object ob;
        mapping my;
        string line, str, attack_skill, skill_type,parry_type;
        object weapon;
     //   int attack_points, dodge_points, parry_points;
        object me=this_player();

        seteuid(getuid(me));

        if(!arg) ob = me;
        else {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
                       }

        my = ob->query_entire_dbase();
        line = sprintf("\n 战斗攻击力 " HIW "%d (+%d)" NOR "\t\t战斗防御力 " HIW "%d (+%d)\n" NOR,
                get_dp(ob,0)/100 + 1, ob->query_temp("apply/damage"),
                (get_dp(ob,2)/2 + (weapon? get_dp(ob,1): (get_dp(ob,1)/2)))/100 + 1, ob->query_temp("apply/armor"));

         line +=sprintf("      武林声望：  " HIC "%10d\n" NOR,ob->query("wlshw"));
         if((int)ob->query("deposit"))
        line +=sprintf("\n 存   款：" HIY"  %12s"NOR,MONEY_D->money_str((int)ob->query("deposit")));
        else line+="\n 存   款：        "+HIW"穷光蛋"NOR+"";
        line += HIG"———————————————————————————————\n\n"NOR;

        write(line);

        return 1;
}

int do_ggoto(string arg)
{
        int goto_inventory = 0;
        object obj;
        string msg;
        object me=this_player();

        if( !arg ) return notify_fail("你要去哪里？\n");

        if( sscanf(arg, "-i %s", arg)  ) goto_inventory = 1;

        if( !arg ) return notify_fail("你要去哪里？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
         if(!obj) {
                        arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                                                        if( file_size(arg)>=0 )
                                return me->move(arg);
                                return notify_fail("没有这个玩家、生物、或地方。\n");
                                }
        }
        if(!goto_inventory && environment(obj))
                obj = environment(obj);
        if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
        me->move(obj);
        return 1;
}

int do_wwhere(string str)
{
        object ob, where;

        if (!str)
                return 1;
        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if (!ob) return notify_fail("现在没这个人.\n");
        where = environment(ob);
        if (!where) return notify_fail("这个人不知道在那里耶...\n");
        printf("%s(%s)现在在%s(%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
                (string)where->query("short"),
                (string)file_name(where));
        return 1;
}

int do_sskills(string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i;
        object me=this_player();

        seteuid(getuid());

        if(!arg) ob = me;
        else {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
        }

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( (ob==me ? "你" : ob->name()) +"目前一共学过"+chinese_number(sizeof(ob->query_skills()))+"种技能：\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
                printf("%s%-40s" NOR " -  %3d/%5d\n",
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        write("\n");
        return 1;
}

int do_ddetect()
{
        string location;

                object me = this_player(),*treasure,env,where;

                location = "未知地点或者不存在";
                treasure = children("/obj/example/stone.c");
                if( sizeof(treasure)>1 )
                {
                        env = environment(treasure[0]);
                        if( objectp(env) )
                                if( env->is_character() )
                                {
                                        where=environment(env);
                                        location = sprintf("%s 的身上. 地点: /%O-%s.",env->query("name"),where,where->query("short"));
                                 }
                                else
                                        location = sprintf("/%O - %s.",env,env->query("short"));

        }
        write(YEL"\n宝物位置: "+location+"\n"NOR);
        return 1;
}

int do_eedit(string file)
{
        object me=this_player();
        if( !file ) return 0;


        if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

        seteuid(geteuid(me));
        ed(resolve_path(me->query_temp("cwd"), file));
        return 1;
}

int do_uupdate(string file)
{
        int i;string err;
        object obj, *inv, me=this_player();

        seteuid( geteuid() );

        if (!file)
                return 0;

                file = resolve_path(me->query_temp("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c";
        if( file_size(file)==-1 )
                return notify_fail("没有这个档案。\n");

  /*      if( file==__FILE__ ) {
                destruct(this_object());
                return 1;
        }*/



        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("你不能在 VOID_OB 里编译 。\n");
                        inv = all_inventory(obj);
                        i = sizeof(inv);
                        while(i--)
                                if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
                                else inv[i] = 0;
                }
                destruct(obj);
        }

 if (obj) return 0;
  call_other(file, "???") ;

       i=sizeof(inv);
       if( obj = find_object(file)) {
                        while(i--)
                                if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
                }

        return 1;
}
