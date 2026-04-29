
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

string ask_me(object who);

void create()
{
	set_name("灵空", ({ "master lingkong", "master","lingkong" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
	set("str",40);
	set("cor",40);
        set("apprentice_available", 20);
        create_family("大招寺", 20, "副主持");
	set("long",
		"灵空高僧已在大招寺主持多年。男女弟子遍布关外。\n"
		);
	set("inquiry", ([
		"葛伦大师": "大师在南方云游。",
	]) );
        set("combat_exp", 9999999);
	set("bellicosity",100);
        set("max_kee",300);
        set("max_gin",900);
        set("max_sen",300);
	set("force",3000);
	set("max_force",2000);
	set("force_factor",50);
	set("max_atman",1000);
	set("atman",1000);
        set("score", 90000);
	set("no_get",1);

        set_skill("strike", 150);
        set_skill("staff", 150);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("dodge", 160);
        set_skill("literate", 180);
	set_skill("iron-cloth", 180);

	set_skill("bloodystrike", 150);
	set_skill("cloudstaff", 180);
	set_skill("bolomiduo", 180);
	set_skill("buddhism", 180);
        set_skill("jin-gang",180);
	set_skill("notracesnow",180);
        set_skill("magic",180);
	set_skill("essencemagic",20);


//	map_skill("strike", "bloodystrike");
	prepare_skill("strike", "bloodystrike");
        map_skill("strike", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("force", "bolomiduo");
        map_skill("parry", "cloudstaff");
        map_skill("dodge", "notracesnow");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");

	set("shen_type",-1);
	setup();
	carry_object(__DIR__"cassock")->wear();
        carry_object(__DIR__"obj/zijinzhang")->wield();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
       command("say 大招寺将有重大修改，先等等好么。\n");
         return;
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

void init()
{
  ::init();
  add_action("give_quest","quest");
}

/*void init()
{
	::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}

/*
// check if bribe is valid
int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
	return(0);
}

// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}
*/
