// /daemon/class/xueshan/sangjd.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("桑吉多", ({ "sangjiduo", "sang" }));
        set("long", "他是金轮法王座下的大弟子。深得法王的真传。\n");
        set("gender", "男性");
        set("age", 47);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 48);
        set("int", 18);
        set("con", 30);
        set("max_kee", 3500);
        set("max_gin", 3500);
	set("max_sen", 3000);
        set("force", 3300);
        set("max_force", 3300);
        set("force_factor", 50);
        set("combat_exp", 1900000);
        set("score", 150000);
	set("shen", -150000);
	set_skill("zang-buddhi", 50);
	set_skill("literate", 35);
        set_skill("force", 200);
        set_skill("banruo", 140);
        set_skill("dodge", 100);
        set_skill("cuff", 200);
        set_skill("parry", 200);
        set_skill("hammer", 200);
        set_skill("wuxinglun", 150);
        map_skill("force", "banruo");
        map_skill("parry", "wuxinglun");
        map_skill("hammer", "wuxinglun");
        set_skill("move", 100);
        map_skill("cuff", "yujiamu-quan");
        set_skill("yujiamu-quan", 100);
	create_family("布达拉宫", 8, "大喇嘛");
        setup();
        carry_object(__DIR__"obj/quan")->wield();
        carry_object(__DIR__"obj/pao2")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "男性" )
	{	
		command("say 我只收男弟子。");
		return;
	}
        command("say 好,现在你就是我的弟子了！");
        command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
}

void init()
{

        object ob;
        mapping fam;

        ::init();
        add_action("give_quest","quest");
}


// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任
务吧！\n" ,who);
    who->set("quest",0);
    who->set("kee",0);
    return(0);
}

