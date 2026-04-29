///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>

inherit ROOM;

void create()
{
        setup();
}

int creature_die(object me)
{
        object *inv,enemy;
        string str;

        if( !me || !userp(me) ) return 0;
        enemy = me->query_temp("last_damage_from");
        if(enemy) {
        str = me->name()+"差点被"+enemy->name()+"杀死了，幸亏当地村民相救才保住性命。";
                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
                }
                me->move(__DIR__"houyuan");
                message_vision(HIY"$N隐隐约约听见一个村民说道：出了新手村，可就没这么幸运了。\n"NOR,me);
                message_vision(HIY"村民们放下$N，匆忙的走了。\n"NOR,me);
                if(me->query("eff_kee")<1) me->set("eff_kee",1);
                if(me->query("eff_gin")<1) me->set("eff_gin",1);
                if(me->query("eff_sen")<1) me->set("eff_sen",1);
                me->unconcious();
        return 1;
}

