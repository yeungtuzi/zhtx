#define MAX_ENV_VARS    20
 
inherit F_CLEAN_UP;
#include <ansi.h>

 
int help();

int main(object me,string arg)
{
        object login_ob,user_ob;
          if( me != this_player(1) ) return 0;

        me=this_player();
        if( me->query("had_resetgift")) return notify_fail("你已经重新分配过一次天赋了，这个指令终身只能使用一次！\n");
        if( me->query("have_resetgift")) return notify_fail("你已经重新分配过一次天赋了，这个指令终身只能使用一次！\n");
        if( me->query("combat_exp")>1000000) return notify_fail("你已经逐渐开始成长了,不能重新分配属性!\n");
        if( me->query("mud_age")>172000) return notify_fail("你的体质已经和你的天赋合而为一，无法重新分配天赋了!\n");
        if( !arg || !(user_ob = find_player(arg)) )
                return help();
        if( !userp(user_ob) || !(login_ob=user_ob->query_temp("link_ob")) )
        {
                write("Cannot find this player's login object.\n");
                return 1;
        }   
        user_ob->set("kar_bak",user_ob->query("kar"));
        user_ob->set("per_bak",user_ob->query("per"));
        user_ob->set("fav_bak",user_ob->query("fav"));
        user_ob->set("spi_bak",user_ob->query("spi"));
        user_ob->set("elo_bak",user_ob->query("elo"));
        user_ob->set("msc_bak",user_ob->query("msc"));
        user_ob->set("wil_bak",user_ob->query("wil"));
        user_ob->set("vis_bak",user_ob->query("vis"));
        user_ob->set("have_resetgift", 1);
        user_ob->set("reset_gift_accquired",1);
        login_ob->set("reset_gift_accquired",1);
        user_ob->save();
        login_ob->save();
        tell_object(user_ob,"请退出并重新连线分配您的天赋属性，\n之后请到长安姬良处"+HIR"ask ji liang about 失去的记忆"+NOR"，可以将您的隐藏天赋复原。\n");
        user_ob->fcommand("quit");
        return 1;
}

int help()
{
   write(@HELP
指令格式: resetgift <玩家自己的id>
经验小于100万，年龄小于17岁的玩家可以使用此指令重新分配修改自己的可显示数值的天赋属性。
每个ID终身只允许使用此指令一次。
HELP
        );
        return 1;
}

