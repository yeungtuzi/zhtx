#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "城隍庙");
	set("long", @LONG
这是一间十分老旧的城隍庙，在你面前的神桌上供奉著一尊红脸的城
隍，庙虽老旧，但是神案四周已被香火薰成乌黑的颜色，显示这里必定相
当受到信徒的敬仰。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"eroad1",
		"west" : __DIR__"square",
	]));
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_magic", 1);
	set("no_poison", 1);
	set("no_get",1);
	set("no_death",1);
	set("no_faint",1);
	set("objects", ([ /* sizeof() == 2 */
		OBJ_PAPER_SEAL : 2,
		__DIR__"npc/keeper" : 1,
//               __DIR__"npc/shizhe" : 1,
		__DIR__"obj/denotation" : 1
	]));

	setup();
}
int valid_enter(object ob) {
        if(!userp(ob)) return -1;
        return 1;
}
