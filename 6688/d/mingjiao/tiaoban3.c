inherit ROOM;
void create()
{
        set("short", "巨舟踏板");
        set("long", @LONG
在你面前是一条巨大的双层海船。船上灯火通明,微风吹过，细滔拍舷，发出有节
奏的“啪啪”声。船身也随之微起微伏。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ship2",
  "west" : __DIR__"ship3",
]));
	set("outdoors","mingjiao");
        setup();
        replace_program(ROOM);
}
