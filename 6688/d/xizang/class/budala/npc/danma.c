// /d/xizang/class/budala/npc/danma.c

#include <ansi.h>

inherit NPC;
inherit F_QUEST;


void create()
{
        set_name(HIC "丹玛"NOR, ({"dan ma", "danma", "master"}));
        set("long", 
"她就是丹玛女活佛,据说是藏边府中佛法修为仅次于达赖喇嘛的人.\n");
        set("gender", "女性");
	set("attitude", "peaceful");
	create_family("布达拉宫", 14, "女活佛");
	set("apprentice_available", 1);
	set("combat_exp", 1999999);
	set("age", 45);
	set("str", 15);
	set("int", 51);
        set("max_kee", 3000);
	set("max_gin", 600);
	set("max_sen", 600);
        set("shen", -500000);
	set("score", 50000000);
	set("force", 3000);
	set("max_force", 1500);
	set("mana", 3000);
	set("max_mana", 1500);
	set("atman", 3000);
	set("max_atman", 1500);

	set_skill("zang-buddhi", 210);
	set_skill("unarmed", 140);
	set_skill("parry", 180);
        set_skill("literate", 200);
        set_skill("banruo", 180);
	set_skill("force", 200);
	set_skill("magic", 200);
	map_skill("force", "banruo");
	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: conjure_magic, "protect" :),
//		(: conjure_magic, "invocation" :)
//	}));
	setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}

void reset()
{
	delete_temp("learned");
        set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
	if (ob->query("gender")!="女性") {
		command("say 我只收女弟子.");
		return;
	}
	if( !query("apprentice_available") ||
		(find_call_out("do_recruit") != -1 )) {
		command("say 我只收一名弟子.");
		return;
	}
	if ((ob->query("per")<20) || (ob->query("spi")<20)
		|| (ob->query("msc")<20)) {
		command("shake");
		command("say 你看上去不适合传我法统,还是请回吧.");
		command("sigh");
	}
	if (ob->query_skill("zang-buddhi", 1) < 100) {
		command("shake");
		command("say 你的佛法修为还太浅,请先听达赖喇嘛讲几年经好吗?");
		return;
	}
	call_out("do_recruit", 2, ob);
}

void do_recruit(object ob)
{
	command("en");
	command("say 跟着我吧.");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "lama");
	add("apprentice_availavble", -1);
}

int accept_learn(object me, string skill)
{
	if( (int)me->query("bellicosity") >100) {
		tell_object(me,"你的杀气太高,我不想教你了.\n");
		return notify_fail("你的杀气太高,我不想教你了.\n");
	}
	//return ::accept_learn(me, skill);
	return 1;
}

void init()
{
        ::init();
        add_action("give_quest","quest");
}

int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务�
桑�\n" ,who);
    who->set("quest",0);
    return(0);
}

