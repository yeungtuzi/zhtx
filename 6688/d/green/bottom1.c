//write by lysh
inherit ROOM;

void create()
{
        set("short", "潭水中");
        set("long", @LONG
这里实在很美，很静。泉水清澈冰凉，可是却见不鱼虾，也许鱼虾都躲到
潭底。这里只有水草在砂石间娥娜起舞，这种感觉不是未曾经历此境的人
所能领略得到的。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"xuanyadi",
  "down":__DIR__"bottom",
  ]));

        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        if (dir=="up") return 1;
        return notify_fail("\n你使劲往下游，可是潭水浮力太大，怎么也游不下去！\n");
            
        
}


