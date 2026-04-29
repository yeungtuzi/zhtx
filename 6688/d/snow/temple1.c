#include <obj.h>

inherit ROOM;

int do_pk_list(string arg) ;
void create()
{
	set("short", "城隍庙内室");
	set("long", @LONG
你走进昏暗的内室，顿时觉得心情压抑起来。只见微弱的灯光下，屋内摆满
了黑色的灵牌，灵牌上刻着的一个个名字你似曾相识，好象都是当年的武林人物。
屋子的角落里摆着一张桌子，桌上有一张摊开的卷轴(list)上似乎写满了字迹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"southwest" : __DIR__"temple",
	]));
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_magic", 1);
	set("no_poison", 1);
	set("no_get",1);
	set("no_death",1);
	set("no_faint",1);
	set("sleep_room",1);
//	set("objects", ([ /* sizeof() == 2 */
//	]));

	setup();
}

void init() {

	add_action("do_pk_list",({ "look","watch" }) );
	add_action("do_no_sleep",({ "sleep" }));

}


int valid_enter(object ob) {
        if(!userp(ob)) return -1;
	if( ob->query("age")<15 || ob->query("combat_exp") < 2000 )  {
		tell_object(ob,"庙祝拦住你道：你小小年纪还是不要进去的好！\n");
		return -1;
	}
	return 1;
}

int do_no_sleep() {
	tell_object(this_player(),"这种地方你也睡得着？\n");
	return 1;
}

int do_pk_list(string arg) {


	int start,line;
	string pklist, *pklistarray;
	object ob=this_player();

	if( !arg || (arg != "list" && arg != "卷轴"))  return 0;

	if(ob->query("sen") < 20 ) return notify_fail("你想看清上面写的是什么，可忽然觉得眼前一阵黑，差点晕倒。\n");
	else ob->add("sen",-15);

	pklist= read_file("/log/PK_SUCCESS");
	pklistarray = explode(pklist,"\n");
		
	line = sizeof(pklistarray);
	if(line<100) start=0;
	else start=line - 100 ;
//	this_player()->start_more(read_file("/log/PK_SUCCESS"));
	ob->more("",pklistarray,start);
	return 1;
}
