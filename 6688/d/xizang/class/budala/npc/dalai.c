// /d/xizang/class/budala/npc/dalai.c

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("达赖喇嘛", ({"da lai lama", "dalai", "master"}));
        set("long", 
"他就是至高无上的达赖喇嘛,据说佛法高深无比,神通广大.\n");
        set("gender", "男性");
	set("attitude", "peaceful");
	create_family("布达拉宫", 5, "活佛");
	set("apprentice_available", 10);
	set("age", 65);
	set("str", 30);
	set("int", 50);
	set("combat_exp", 200009999);
	set("max_kee", 87000);
	set("max_gin", 26000);
	set("max_sen", 16000);
	set("score", 100000000);
	set("shen", -3000000);
	set("force", 10000);
        set("max_force", 8000);
        set("mana", 10000);
        set("max_mana", 8000);
        set("atman", 10000);
        set("max_atman", 8000);
	set_skill("zang-buddhi", 220);
	set_skill("iron-cloth", 220);
	set_skill("jin-gang", 220);
	set_skill("parry", 200);
        set_skill("literate", 200);
        set_skill("banruo", 200);
	set_skill("force", 200);
	set_skill("magic", 200);

	map_skill("force", "banruo");
	setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 10);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else {
			if (ob->query_skill("zang-buddhi", 1) < 200) {
	command("say 你的佛法修为还太浅,请先听(listen)我讲几年经再说.");
	return;
			} else call_out("do_recruit", 2, ob);
		}
        } else {
                command("say 我现在累了，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
                command("smile");
                command("say 很好，很好，很好。");
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
        if( (int)me->query_skill(skill, 1) > 
		(int)me->query_skill("zang-buddhi", 1) ) {
	tell_object(me, "你的佛法修为进展太慢,不要浪费时间在别的地方了!\n");
return notify_fail("你的佛法修为进展太慢,不要浪费时间在别的地方了!\n");
	}
	if( (int)me->query("bellicosity")>
		(int)me->query_skill("zang-buddhi", 1)*10) {
		tell_object(me, "佛门弟子,不可如此嗜杀.\n");
		return notify_fail("佛门弟子,不可如此嗜杀.\n");
	}
        return ::accept_learn(me, skill);
}

void init()
{

        object ob;
        mapping fam;

        ::init();
        add_action("give_quest","quest");
}

int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

