// Room: /open/hihi/menfang1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"门房"NOR);
	set("long", @LONG
这里是镖局的大门，虽然自从林老镖头无故失踪后，镖局的生意差了些，房
子和大门也没怎么修葺，但还能看出原来兴旺时镖局的整个格局是非常大的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jie21",
  "west" : __DIR__"bj",
]));

	setup();
	replace_program(ROOM);
}
