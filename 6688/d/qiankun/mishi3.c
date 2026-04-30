//ROOM:/d/qiankun/mishi3.c
//by masterall
//2003.6.30 

#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{
        set("short", HIG"乾坤教密室"NOR);
        set("long", @LONG
这是乾坤教的一间密室，四周通风良好，显然有气孔与外界相连，室中央
有一潭清水，看起来挺深的。房间里光线极暗，隐隐的有青光闪动，似乎
密室的角落里还坐着一个人，你虽看不到他的存在，但是可以感觉到他的
杀气！
LONG
        );

        set("objects",([
                       __DIR__"npc/lin" : 1,
                      ])  );
           
 
        setup();

}

void init()
{
        add_action("do_dive", "dive");
}

int do_dive(string arg) 
{
        object me;
        // 2026-04-30: unused variable commented out
        // object obj;
        object ob;
        me=this_player();
        
        if ( (int)me->query("kee") < 1500 )
             { 
                        tell_object(me, "你这人还是别下去的好。\n"); 
                        return 1;
             }  

         if( ob=present("lin pingzhi", this_object()))
         {
              message_vision(HIB "林平之一声阴笑：“此地乃本教机关重地，哀家受教主重托看守此处，请阁下先过了哀家这一关！”\n" NOR,this_player());
              return 1;
         }      
             
        me->receive_damage("kee",1000); 
        me->receive_damage("gin",10);
        message_vision("$N一头往水中扎了进去。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N扎进了水中。\n",me);
                me->move("/d/qiankun/mishi4");
                tell_room(__DIR__"mishi4",HIG"上面露出微光,水流很急。\n你终于游到了另一个房间，深深的吸了一口气！"NOR);
                return(1);
        }
        return(1);  
}
