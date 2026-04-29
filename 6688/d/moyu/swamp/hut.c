// swamp1.c
// by meteoric
#include <ansi.h>
#include <room.h>
#define MOYU_DIR "/d/moyu/"

inherit "/ldg/std/dyna_room.c";
void create()
{
	set("short", "黑沼小屋");
	set("long", @LONG
你辨不清东西南北，只好随意而行，只觉的似乎越行越是迂迴迢遥，岂知不到
一盏茶时分，便隐隐看见一点亮火赫然已在眼前。你心头大喜，向前直奔。只
听你“啊哟”一声，双足已陷入泥中，直没至漆，急忙提气后跃，硬生生把两
只脚拔了出来，一股污泥的臭味刺鼻而来。向前望去，眼前一团茫茫白雾裹着
两间茅屋，幽幽灯光便从茅屋中射出。
LONG );

        set("exits", ([
              "enter"     : __DIR__"hut/hut1" 
        ]) );


//        create_door("enter", "木门", "out", DOOR_CLOSED);
	setup();
}

/*  int valid_leave(object me,string dir)
{
	object obj,*old_npc;
	if(!me->query_temp("黑沼小屋") && dir=="enter")
	{
		old_npc = children(MOYU_DIR+"npc/hut_guard");
		if( sizeof(old_npc)<1 )
		{
	        	obj=new(MOYU_DIR+"npc/hut_guard");
			message_vision(BLU"忽然间，一条如影似魅的人影飘然飞来。\n",me);
			obj->move(this_object());
		}
		else obj=old_npc[0];
		
		message_vision(BLU"一双明若冷月、亮如灼日、毒若蛇嫩狠如利剑的眼睛，冷冷地、冷冷地盯着你。\n"NOR,me);
		if(me->query_temp("enter_num")<2+random(3))
		{
			me->add_temp("enter_num",1);
			return notify_fail(RED+obj->query("name")+RED"哼了一声：不得乱闯，否则杀无赦！\n"NOR);
		}
		else
		{
			me->set_temp("enter_num",0);
			message_vision(RED"$N"+RED"哼了一声：找死！\n"NOR,obj);
			obj->kill_ob(me);
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}*/
