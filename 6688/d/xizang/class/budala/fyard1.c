// /d/xizang/class/budala/fyard1.c

inherit ROOM;

void create()
{
        set("short", "前院");
        set("long", @LONG
这里是布达拉宫的前院,两边沿着甬道是各种工匠居住和工作的地方,以及各
种物资仓库.北边台阶上就是前殿.
LONG
        );
        set("exits", ([
          "south" : __DIR__"foregate",
          "north" : __DIR__"fyard2",
           "east" : __DIR__"path4",
           "west" : __DIR__"path1",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
