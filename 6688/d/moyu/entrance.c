// 魔域
// by meteoric
#include <ansi.h>

inherit ROOM;


void create()
{
	set("short", "小客店");
	set("long", @LONG
这是一个小酒家，破烂的酒旗在北风中飞舞。北面的路通往雪原，雪原之上群兽出没，盗匪猖獗，
因此很少有行人来此，但是据传在极北之地有一武学圣地－－〔冰宫〕，里面金银财宝，武功秘籍
不计其数。因此每年都有一些武林人物路经这里去寻找这传说中的圣地，然而数百年来，在去的人
中没有一个人回来。但是又有谣传说曾经有一个人回来了，而且此人是数百年来真正进入过冰宫的
第一人。
LONG
	);

	set("valid_startroom",1);
	set("sleep_room",1);
	set("no_fight",1);  
	set("no_poison",1);
	set("no_magic",1);  
        set("no_steal",1);
        set("no_get",1);
	set("no_faint",1);
	set("no_death",1);
	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"xueyuan/xueyuan1",
	  "south" : "/d/road/rfttocy4",
	]));                                     

	set("objects", ([
			__DIR__"npc/waiter" : 1,
		])
	);
	setup();
}

int init()
{
	add_action("do_buy","buy");
}

int do_buy()
{
	write("在这里买东西？不怕别人抢了你的钱？\n");
	return 1;
}

int valid_leave(object me,string dir)
{
	object *inv;
        int i;

	if( dir != "north") return 1;
          if(me->query("combat_exp")<1000000)
		return notify_fail("店老头告诉你：前途险恶，我看你还是回去好好学功夫吧。");
	else if(!me->query_temp("go_moyu"))
	{
		me->set_temp("go_moyu",1);
		return notify_fail(
		"店老头告诉你：前途险恶，数百年来无人能活着回来。\n"
		"你真的想要过去？\n"
		);
	}
		
	inv = all_inventory(me);
        for( i=0;i<sizeof(inv);i++) 
        {
                if( inv[i]->is_character() )
                {
			return notify_fail("你不能背着"+inv[i]->query("name")+"进去!\n");	
		}
        }
        write(WHT"店老头黯然长叹一声：又一个送死的！\n"NOR);
	write(YEL"你鼓足勇气，踏上了险恶的征程。\n"NOR);
	write(WHT"大雪漫天，你已经辨不清东南西北，也找不到回去的路了。\n"NOR);
	return 1;
}
