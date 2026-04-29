#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name( HIY"大内密宝之"+HIW"－"MAG"七"+YEL"彩"+CYN"宝石"+RED"戒指"NOR , ({ "diamond ring", "ring" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  "这是逍遥派掌门信物，执戒指者即为逍遥派本代掌门。\n但逍遥派一向极少与朝廷有所往来，这枚戒指十有八九是赝品。\n");
                set("unit", "枚");
                set("value", 0);
                set("no_drop",1);
                set("material", "diamond");
                set("armor_prop/armor_vs_force", 100);
                set("armor_prop/armor", 50);
                set("armor_prop/spells", 20);
                set("wear_msg", "$N将$n拿出戴在右手无名指上。\n");
        }
        setup();
        call_out("check",5);
}

void check()
{
        object me;
        string name;
        string *conditions=({}),*list,arg;
        int i,flag;
        string eqflag;

        remove_call_out("check");
        call_out("check",5);

        name = query("name");
        me=environment();
        if(!me) return ;
        if( me->is_character() &&  ( eqflag=query("equipped")) && ( eqflag =="worn")  )
        {
                if(!living(me))
                {
                        message_vision(name+YEL"发出嗡嗡声响，一道七彩光环在$N身边盘旋环绕，经久不散。\n",me);
                        me->revive();
                        return;
                }
                
                list = get_dir("/daemon/condition/");
        
                i = sizeof(list);
                conditions = ({});
                flag = 0;
                while( i-- )
                {
                        arg = list[i];
                        if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                                conditions += ({arg[0..strlen(arg)-3]});
                        conditions += ({"iceshock"});
                        conditions += ({"threesmile"});
                        conditions += ({"zhang_qi"});
                        conditions += ({"fushi-du"});
                }
        
                i = sizeof(conditions);

                while(i--) 
                {
                        if( me->query_condition(conditions[i]) > 0 )
                        {
                                me->apply_condition(conditions[i],0);
                                flag = 1;
                        }
                }                               
                if(flag)
                {

                        message_vision(name+GRN"上面突然闪过一阵异芒，从$N手指出吸出一道黑气。\n"NOR,me);
                        return;
                }
        }
}

