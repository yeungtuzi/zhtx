
inherit ROOM;

void create()
{
	set("short", "襄阳");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rlytoxy3",
	"west" : "/d/road/rxytowds0",
          "northeast" : "/d/qiankun/shanlu4",
	"southeast" : "/d/road/rxytohk0",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/u/m/masterall/guojing" : 1,
]));

	setup();
	replace_program(ROOM);
}
