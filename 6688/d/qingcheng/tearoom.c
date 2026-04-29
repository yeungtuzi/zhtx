// Room: /class/qingcheng/tearoom.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "[35m茶室[2;37;0m");
	set("long", @LONG
这里是青城派接待宾客的茶室，厅中摆了一张桌几，上面摆著一块大红镶金
桌巾，靠东壁面西设著半旧青缎靠背引枕，两张太师椅座。桌几上有一精致的茶
壶，旁有盛好的上等茗茶。
LONG
	);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
			]));
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"sleeproom",
		"west" :__DIR__"sleeproom1",
		"south" : __DIR__"square",
		"north" :__DIR__"xiaojing",
			]));
	create_door("north", "小门", "south", DOOR_CLOSED);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/renda" : 1,
			]));
	
	setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "青城派") && (dir == "east"||dir=="west"||dir=="north")&& 
                objectp(present("jia renda", environment(me))))
           return notify_fail("贾人达道：你不是青城弟子，请别进去。\n");
	if ((me->query("combat_exp")<=2000)&& dir=="north")
	   return notify_fail("你的经验不够!\n"); 
        if( me ->query("gender")=="男性" && dir=="east")
                return notify_fail("你是男弟子，不要进女弟子休息室。\n");
        if( me ->query("gender")=="女性" && dir=="west")
                return notify_fail("你是女弟子，不要进男弟子休息室。\n");
 
        return ::valid_leave(me, dir);
}
