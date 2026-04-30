// /d/xizang/m_road1.c

inherit ROOM;

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
这里是一大片冰柱构成的丛林.
LONG
        );
        set("exits", ([
        "southeast" : __DIR__"m_road",
            "north" : __DIR__"ice1",
]));
	set("outdoors", "xizang");
        setup();
}

int valid_leave(object me, string dir)
{
        // 2026-04-30: unused variable commented out
        // object room;
        string outexit;
        if (dir == "north") {
                if ( query("exits/north") ) delete("exits/north");
                switch (random(4)) {
                case 0:
                        outexit = __DIR__"ice1";
                        break;
                case 1:
                        outexit = __DIR__"ice2";
                        break;
                case 2:
                        outexit = __DIR__"ice3";
                        break;
                case 3:
                        outexit = __DIR__"ice4";
                        break;
                }
                set("exits/north", outexit);
        }
        return 1;
}
