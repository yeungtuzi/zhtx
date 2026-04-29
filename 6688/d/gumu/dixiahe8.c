// /d/xingxiu/dixiahe8.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "地下河");
        set("long", @LONG
    这是一条地下河，表面上看起来很平静。河里有许多
漩涡，游起来该注意一下，别走进漩涡里去了。北边有些光亮，
好象到了岸了。
LONG
        );

        set("exits", ([
    /*    "northeast" : __FILE__,
        "southeast" : __FILE__,
        "southwest" : __FILE__,
        "northwest" : __FILE__,*/
        "north" : __DIR__"hean",
        "west" : __DIR__"dixiahe2",
        "south" : __DIR__"dixiahe6",
        "east" : __DIR__"dixiahe3",
        ]));
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_kee;

        current_kee = me->query("kee");
        if (current_kee<50) {
          write("你已经感到不行了，冥冥中你觉得被水冲出暗河。\n");
          me->move(__DIR__"xidi");
          me->unconcious();
        }

        if (current_kee>0 && current_kee<=100) {
            write("你已经游得精疲力尽了。\n");
            me->set("water",0);
        }

        if (current_kee>50) {
            me->set("kee",current_kee-50);
        }
    //    if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
      //     return notify_fail("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
        return ::valid_leave(me, dir);
}

