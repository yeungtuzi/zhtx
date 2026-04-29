// Room: /open/hihi/beikou1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"福州北门"NOR);
	set("long", @LONG
  这里是福州北门。往南就进入了闽南最繁华的城市福州了。福州地理位置
很好，发展又快，可算得是南国城市中一颗闪耀的明珠。这里民风很好，但因为
都是说当地的闽南话，外地来客很少能听懂本地方言，所以与中原的交往并不是
很多，一般都是外出的人多，移进的人少.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"beikou1",
	  "south" : __DIR__"jie11",
		]));

	set("outdoor","qinglong");
	setup();
	replace_program(ROOM);
}
