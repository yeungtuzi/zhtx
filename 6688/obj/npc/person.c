// /obj/npc/person.c
// 镖局用npc,陌生人
// NPC_DIR"person"
// by mscat

#include <ansi.h>

inherit NPC;

void set_level(int level_number);
int make_robber();
string long_msg();

void create()
{
	set_name("陌生人", ({ "strange person", "person", "ren"}));
	if (random(10)>4) set("gender", "男性" );
		else set("gender", "女性" );
	set("age", 16+random(40));
	set("long", (: long_msg :) );
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}

void set_level(int level_number)
{
	set("difficulty", level_number);
	set("chat_chance", 5+5*random(level_number+1)); //max 55
	set("chat_msg", ({
		(: make_robber :)
	}));
}

int make_robber()
{
	object room, me, escort, robber, ob;
	int level_number, i;
	me=this_object();
	level_number=(int)me->query("difficulty");
	room=environment(me);
	CHANNEL_D->do_channel(me, "rumor",
		sprintf("有位富商正在%s附近赶路",room->query("short")));
	if (level_number==0) {
		command("say 天气很好...");
		return 1;
	}
	if (!room->query("no_fight"))
	command("say 这里风高林暗,不要有强人出没才好....");
// if has difficulty, make robbers
	if(objectp(escort=me->query_leader()) &&
		level_number>0 && random(escort->query_kar())<10) {
		for(i=0;i<1+random(1+level_number/4);i++){
			robber=new(NPC_DIR"robber");
			robber->set_level(1+random(level_number));
			robber->move(room);
        message_vision(HIR"突然有人从斜刺里跳出来,拦住了$N的去路!\n"NOR,
                        escort);
			robber->do_rob(me);
//			escort->kill_ob(robber);
		}
	}
	return 1;
}

string long_msg()
{
        object escort;
        if(!objectp(escort=this_object()->query_leader())
                || this_player()!=escort)
		return "这是委托镖局护送的一位陌生旅客.\n";
	return "这是你负责护送的一位陌生旅客,,本次任务的目的地是"+
                (string)escort->query("marks/biaoju_task")+"\n";
}
