#include <ansi.h>
inherit ITEM;


void create()
{
        set_name( "破扫帚" , ({ "saozhou" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  "这是一件破破烂烂的扫帚。\n");
                set("unit", "枚");
                set("value", 0);
                set("no_drop",1);
                set("material", "wood");
        }
        setup();
        call_out("check",1);
}

void check()
{
        object me;
        string name;
        // 2026-04-30: unused variable commented out
        // string *conditions=({}),*list,arg;
        // 2026-04-30: unused variable commented out
        // int i,flag;
        // 2026-04-30: unused variable commented out
        // string eqflag;

        remove_call_out("check");
        call_out("check",1);

        name = query("name");
        me=environment();
        if(!me) return ;
        if(userp(me))return 0;

                if(!living(me))
                {
//                        message_vision(name+YEL"发出嗡嗡声响，一道七彩光环在$N身边盘旋环绕，经久不散。\n",me);
                        me->revive();
                        return;
                }

                

                        me->clear_condition();
                        me->set("eff_sen",me->query("max_sen"));
                        me->set("sen",me->query("max_sen"));
                        me->set("eff_gin",me->query("max_gin"));
                        me->set("gin",me->query("max_gin"));
                        me->set("eff_kee",me->query("max_kee"));
                        me->set("force",me->query("max_force")*2);
                        me->set("force_factor",500);
                        me->set("kee",me->query("max_kee"));
                        me->set("water", 2100);
                        me->set("food", 2100);
                        return;
                                       

}

