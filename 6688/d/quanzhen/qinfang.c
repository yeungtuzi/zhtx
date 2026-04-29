// Room: /u/hacky/quanzhen/shifang.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;
int pull(string arg);
int draw(string arg);

void create()
{
	set("short", "寝房");
	set("long", @LONG
师房是王重阳休息的地方,内有一张宽大的床,你看着看着也想躺上去睡一觉了,
房间的角落上有一张字画(picture),除此再没有什么别的动西，北边是师房.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shifang.c",
]));
        set("item_desc", ([
             "picture" : "一张王重阳自己所做的字画，年月颇久了，但是却没有什么灰尘，
字画的后面似乎有些玄机.\n"
	]));
	set("no_clean_up", 0);
//	replace_program(ROOM);
}

void init()
{
	add_action("do_draw", "draw");
        add_action("do_pull", "pull");
}


int do_pull(string arg)
 {
    object me;
    me=this_player();
    if(!arg) return notify_fail("你要干什么?\n");
    if(arg=="picture")
   {
    tell_object(me,"你小心翼翼的将字画翻上去，竟然发现在字画的后面有三个可以拉动的绳子(rope).\n");
    me->set_temp("have_pull",1);
    return 1;
   }
 }
void check_trigger()
{
	object room;

	if( (int)query("first_trigger")==3
	&&	(int)query("second_trigger")==5
        &&      (int)query("third_trigger")==4
	&&	!query("exits/down") ) {
		message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
			this_object() );
		set("exits/down", "/d/gumu/bingqishi");
		if( room = find_object("/d/gumu/bingqishi") ) {
			room->set("exits/up", __FILE__);
			message("vision", "天花板忽然发出轧轧的声音，露出一个向上的阶梯。\n",
				room );
		}
		delete("first_trigger");
		delete("second_trigger");
                delete("third_trigger");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖住了。\n",
		this_object() );
	if( room = find_object("/d/gumu/bingqishi") ) {
		room->delete("exits/up");
		message("vision", "天花板忽然发出轧轧的声音，向上的阶梯又缓缓地收了回去。\n",
			room );
	}
	delete("exits/down");
}


int do_draw(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;
        if(!this_player()->query_temp("have_pull"))
         return notify_fail("你要干什么?\n");

	if( arg=="rope" ) {
		write("你试著拉动绳子，似乎可以上下拉动....\n");
		return 1;
	}
	if( sscanf(arg, "rope %s", dir)==1 ) {
		if( dir=="first" ) {
			message_vision("$N将第一个绳子往上一拉...，忽然「喀」一声绳子又移回原位。\n", this_player());
			add("first_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="second" ) {
			message_vision("$N将第二个绳子往上一拉...，忽然「喀」一声绳子又移回原位。\n", this_player());
			add("second_trigger", 1);
			check_trigger();
			return 1;
		} else  if( dir=="third" ) {
			message_vision("$N将第三个绳子往上一拉...，忽然「喀」一声绳子又移回原位。\n", this_player());
			add("third_trigger", 1);
			check_trigger();
			return 1;
	        } else { 
			write("你要将床推向那个方向？\n");
			return 1;
		}
	}
}


void reset()
{
	::reset();
	delete("first_trigger");
	delete("second_trigger");
        delete("third_trigger");
}
