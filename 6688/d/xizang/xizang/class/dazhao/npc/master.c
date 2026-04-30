// /d/xizang/class/dazhao/npc/master.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

void create()
{
	set_name("班禅大师", ({ "master banchan", "master","banchan" }) );
	set("gender", "男性" );
	set("age", 71);
	set("int", 49);
        set("apprentice_available", 10);
        create_family("大招寺", 32, "主持");
	set("long","他就是被誉为珍宝的班禅大师,佛法高深无比.\n");
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大招寺的木屋里。",
	]) );
        set("combat_exp", 19999999);
        set("score", 90000);
	set("shen", -10000);
	set("force", 10000);
	set("max_force", 5000);
	set("mana", 10000);
	set("max_mana", 5000);
	set("atman", 10000);
	set("max_atman", 5000);
        set_skill("unarmed", 100);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("literate", 150);
	set_skill("magic", 150);
	set_skill("bolomiduo", 200);
	set_skill("zang-buddhi", 200);
	set_skill("shield", 180);
	set_skill("essencemagic", 150);

        map_skill("force", "bolomiduo");
	map_skill("unarmed", "shield");
//      map_skill("literate", "zang-buddhi");
        map_skill("magic", "essencemagic");
	
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.shield" :),
	}) );

	setup();
	carry_object(__DIR__"obj/y_cloth")->wear();
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
                else
                        call_out("do_recruit", 2, ob);
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
void init()
{

        object ob;
        // 2026-04-30: unused variable commented out
        // mapping fam;

        ::init();
        add_action("give_quest","quest");
}               
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}


