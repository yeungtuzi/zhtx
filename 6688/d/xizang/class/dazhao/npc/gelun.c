// /d/xizang/class/dazhao/npc/gelun.c

inherit NPC;
inherit F_MASTER;

void kickout();
void create()
{
	set_name("葛伦", ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
        set("apprentice_available", 20);
        create_family("大招寺", 20, "主持");
	set("long",
		"葛伦高僧早已坐化多年,你看到的其实是他的神识所化幻象。\n");

        set("combat_exp", 99999990);
	set("max_mana", 10000);
	set("mana", 20000);
	set("max_atman", 10000);
	set("atman", 20000);
	set("max_force", 10000);
	set("force", 20000);

        set_skill("literate", 200);
	set_skill("magic", 200);
	set_skill("zang-buddhi", 200);
	set_skill("essencemagic", 200);
        map_skill("magic", "essencemagic");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: kickout :),
	}));
	set("chat_chance", 5);
	set("chat_msg", ({
		(: command, "consider" :),
		"大家明明都是佛教正宗,为什么中原武林总把我们当作邪派?",
		(: command, "sigh" :),
		"难道就是因为我们不戒荤食,不戒嫁娶?",
		(: command, "shake" :),
		"可是佛教本义并不要求素食和禁欲啊....."
	}));
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
	if(ob->query("class")!="lama") {
		command("say 我只收喇嘛教中人.");
		return;
	}

        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本主持今天已经收了二十个弟子，不想再收徒了。");
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

void kickout()
{
	object* obs;
	int i;

	obs=this_object()->query_enemy();
	for(i=sizeof(obs)-1;i>=0;i--) {
		message_vision("葛伦一脚把$N踢了出去\n", obs[i]);
		if(userp(obs[i])) 
		{
			obs[i]->move("/d/xizang/class/dazhao/tower");
			obs[i]->receive_damage("gin", 100);
			obs[i]->receive_damage("kee", 200);
			obs[i]->receive_damage("sen", 100);
		}
        	else
			destruct(obs[i]);
	}
}
