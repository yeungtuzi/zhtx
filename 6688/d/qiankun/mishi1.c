//ROOM:/d/qiankun/mishi1.c
//by masterall
//2003.6.30              
        
#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{                           
        set("short", RED"乾坤教密室"NOR);
        set("long", @LONG
这是乾坤教的一间密室，四周通风良好，显然有气孔与外界相连，下面的地板也有
所松动，房间里光线极暗，隐隐的有青光闪动，似乎密室的角落里还坐着一个人，
你虽看不到他的存在，但是可以感觉到他的杀气！
LONG
        );                                        
             
        set("objects", ([
                  __DIR__"npc/mei": 1
]));                         

        setup();
}      


void init()
{
        add_action("do_dig", "dig");
}


int do_dig(string arg)
{
        object me;
        object ob;
        me = this_player();
        
        if ( !arg || arg != "地板" )
                return notify_fail("你要挖什麽?\n");
                       
        if ( ((int)me->query_skill("unarmed",1) < 150) ) { 
                tell_object(me, "你臂力太低，挖不动。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<1200))
             {tell_object(me, "你体力不太够喔！\n");  
              return 1;
             }
         if( arg == "地板" && ob=present("mei chaofeng", this_object()))
         {
              message_vision(HIB "梅超风发出一声怪叫：“此地乃本教机关重地，我负教主之命看守此处，请阁下先过了我这一关！”\n" NOR,this_player());
              return 1;
         }
 
        me->receive_damage("gin",15);
        me->receive_damage("kee",300);
        message_vision("$N拿出随身带的快刀，挖了起来。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N忽然一脚踏空，掉了下去。\n",me); 
                me->move(__DIR__"mishi2");
                tell_room(__DIR__"mishi2", BLK"你从上面掉了下来，摔得屁股好疼！\n"NOR);
                me->receive_damage("kee", 1000);
                me->receive_damage("gin", 50); 
             return(1);
        }
        return(1);
}


