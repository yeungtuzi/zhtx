// /d/xizang/class/dazhao/dazhaotemple.c

inherit ROOM;

void create()
{
        set("short", "大招寺门");
        set("long", @LONG
宫殿高四十丈，宽一百二十丈。连绵蜿蜒的雉堞，高耸在山崖上的城堡，
古老的寺院、禅房、碑碣、楼阁、算不清的窗牖帷帘，看来瑰丽而条和，就
象是梦境，就象是神话。
LONG
        );
        set("exits", ([
//  "east" : "/u/m/mscat/xizang/octostreet",
  "east" : "/d/xizang/octostreet",
  "west" : __DIR__"templeyard",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);

}
