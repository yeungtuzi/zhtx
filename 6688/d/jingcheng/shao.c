#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"纵横商号"NOR);
        set("long", @LONG
   这就是大家又爱又恨的纵横商号, 你可以在这自由买卖.
商号老板在墙上用丹笔写了几个斗大的字(zhaopai),有好事
者在下面加了一句(pingyu). 墙上还贴着买卖需知(note)
LONG         
        );
        set("item_desc", ([
                "zhaopai" : RED "你就是上帝！\n\n" NOR,
                "pingyu" : BLK "信不信由你！\n\n" NOR,
                "note" : @LONG
                "list" 查看现在有什么东东可买
                "value" 给你想卖的东东估价
                "sell" 卖东东
                "buy" 买东东
LONG
                ]));
        set("exits", ([ 
 "north" :__DIR__"zhq1",
        ]));
      set("objects", ([
                __DIR__"npc/tang" : 1,
  ]));
        setup();
        replace_program(ROOM);
}
