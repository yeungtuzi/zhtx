// /d/xizang/class/budala/foregate.c

inherit ROOM;

void create()
{
        set("short", "宫门");
        set("long", @LONG
这里是布达拉宫的正门.两边是宫门守卫值班的守卫室和了望楼.布达拉
宫既是西藏的宗教中心,也是行政中心,藏边府实行政教合一制, 至高无上的
达赖活佛同时也是藏边府的最高行政首脑.布达拉宫内附设有断事司,负责整
个藏边的行政事务,与一般地方的官府作用相当.宫内另有僧侣匠人等居住和
工作的地方.
LONG
        );
        set("exits", ([
      "southdown" : __DIR__"stair6",
          "north" : __DIR__"fyard1",
           "east" : __DIR__"ftower",
           "west" : __DIR__"guard",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"npc/bguard" : 2,
                ]));
        setup();
        replace_program(ROOM);
}
