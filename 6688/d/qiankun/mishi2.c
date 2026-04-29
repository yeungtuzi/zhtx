//ROOM:/d/qiankun/mishi2.c
//by masterall
//2003.6.30 

#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{
        set("short", HIY"乾坤教密室"NOR);
        set("long", @LONG
这是乾坤教的一间密室，四周通风良好，显然有气孔与外界相连，旁边有个
暗门好像可以打开，房间里光线极暗，隐隐的有青光闪动，似乎密室的角落
里还坐着一个人，你虽看不到他的存在，但是可以感觉到他的杀气！
LONG
        );

        set("item_desc", ([
                "door": "一扇精铁打铸的暗门，关的严严密密，上面锈迹斑斑好像年代已经很长了。\n",
                        ]) );
        set("objects",([
                       __DIR__"npc/zhou" : 1,
                      ])  );

        setup();
}

void init()
{
   add_action("do_open","open");
}
int do_open(string arg)
{
         object ob;
         if (arg!="door") return notify_fail("你要开什么？\n");
         if(query("exits/south")) return notify_fail("门已经是开的了");
         if( arg == "door" && ob=present("zhou zhiruo", this_object()))
         {
              message_vision(HIB "周芷若柳眉一竖，嗔道：“此地乃本教机关重地，教主责成小女子看守此处，请阁下先过了奴家这一关！”\n" NOR,this_player());
              return 1;
         }
              message_vision("$N将暗门打开\n",this_player());
              set("exits/enter",__DIR__"mishi3");
              call_out("closedoor",4);
              return 1;
}
int closedoor()
{  
        if( !query("exits/south") ) return 1;
        message("vision","暗门自己关上了。\n", this_object());
             delete("exits/enter");
        return 1;                
}

