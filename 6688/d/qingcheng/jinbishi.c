// Room: /open/hihi/keep4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"禁闭室"NOR);
	set("long", @LONG
这里是青城的禁地，一般人是不允许进这里的。虽然说青城是名门正派，但
它往往有些做法跟中原的一些武林门派都大不一样。但俗话又说，人不犯我，我
不犯人。所以就算你看不惯，也没有人专门去刺探他人门派的秘密。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"zoulang2",
                    ]));
 
        set("objects",([
      __DIR__"zhennan":1,
                      ]));

	

	setup();
	
}
