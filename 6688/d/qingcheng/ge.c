// Room: /open/hihi/ge.c
#include <ansi.h>
inherit ROOM;

void create()
{	object ob;
	object shielf;
	set("short", MAG"藏经阁"NOR);
	set("long", @LONG
这里是青城的藏经阁，里面的书架上摆满了各种各类的有关武术的经书。
能进这里读书的青城派弟子无一不是同辈之中的佼佼者。近来青城自从木道人
不知归隐何处后，年青一辈的高手越来越少了，此地的经书也少人看了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
                 "south" : __DIR__"zoulang",
                      ]));

        set("objects",([
         __DIR__"obj/shielf":1,
                   ]));
	setup();
	shielf=present("shielf",this_object());
	    switch( random(6) ) {
                case 0:
                       ob=new(__DIR__"obj/qforce");
			ob->move(shielf);
                        break;
 		case 1:
                       ob=new(__DIR__"obj/zhang");
			ob->move(shielf);
                        break;
		case 2:
                       ob=new(__DIR__"obj/pine-sword");
			ob->move(shielf);
                        break;
		case 3:
                       ob=new(__DIR__"obj/steps");
			ob->move(shielf);
                        break;
		case 4:
                       ob=new(__DIR__"obj/sword");
			ob->move(shielf);
                        break;
		case 5:
                       ob=new(__DIR__"obj/force");
			ob->move(shielf);
                        break;
		}
		
}
