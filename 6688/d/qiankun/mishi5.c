//ROOM:/d/qiankun/mishi5.c
//by masterall
//2003.6.30 

#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{
        set("short", HIB"乾坤教密室"NOR);
        set("long", @LONG
这是乾坤教的一间密室，四周通风良好，显然有气孔与外界相连，东边的那面
墙是用石头砌成的，似乎有些异样。房间里光线极暗，隐隐的有青光闪动，似
乎密室的角落里还坐着一个人，你虽看不到他的存在，但是可以感觉到他的杀
气！
LONG
        );

        set("objects",([
                       __DIR__"npc/guzhu" : 1,
                      ])  );
      set("item_desc", ([
       "wall" : "这是一堵黑黝黝的石壁。\n",
       "石墙" : "这是一堵黑黝黝的石壁。\n",
    ]) );
        setup();

}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{   object me=this_player() ;
    object ob;
    int n;
    n = this_player()->query("force");
    if( !arg || arg!="石墙" ) 
          return notify_fail("你要打碎什么?\n");
if( arg == "石墙" && ob=present("gu zhu", this_object()))
         {
              message_vision(HIB "孤竹一声冷笑：“此地乃本教机关重地，我受教主之重任来此看守，阁下务必踏着我的尸身才能前进！”\n" NOR,this_player());
              return 1;
         }

    message_vision(
    "$N深吸一口气，双掌同时拍出。\n", this_player());
        
    if (n>=5000) {
        message_vision(
        HIW"$N只听一声轰响，$N把石壁震塌了！\n"NOR, this_player());
        set("exits/enter", "/d/qiankun/entrance");
        this_player()->set("force",n-2000);
        remove_call_out("close");
        call_out("close", 5, this_object());
         }
    else {
        message_vision(
        BLK"$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n"NOR, this_player());
       this_player()->set("force",0);
    }
    return 1;

}

void close(object room)
{
    message("vision","石块稀里哗拉坍塌下来，石壁又恢复了原状。\n", room);
    room->delete("exits/enter");
}      

