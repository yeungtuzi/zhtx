// /d/xizang/class/budala/boy.c

inherit ROOM;

void create()
{
        set("short", "男弟子休息室");
        set("long", @LONG
这里是供布达拉宫的男弟子休息的地方.
LONG
        );
        set("exits", ([
                "west" : __DIR__"easthall",
        ]));
        setup();
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_faint",1);
        set("family","布达拉宫");

}
