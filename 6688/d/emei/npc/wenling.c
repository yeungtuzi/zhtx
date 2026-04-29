//
//create bye cuer
inherit NPC;
#include "/d/emei/npc/wen.h"
void create()
{
        set_name("文凌师太", ({
                "wenling shitai",
                "wenling",
                "shitai",
        }));
        set("long",
                "她是一位年轻师太。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_kee", 500);
        set("max_gin", 200);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 40);
        set("combat_exp", 10000);
        set("score", 100);
        set_skill("force", 60);
        set_skill("linji-zhuang", 60);
        set_skill("dodge", 70);
        set_skill("zhutian", 70);
        set_skill("fuliu-jian", 70);
        set_skill("sword", 70);
        set_skill("parry", 60);
        set_skill("buddhism", 70);
        set_skill("literate", 60);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "fuliu-jian");
        prepare_skill("sword", "fuliu-jian");
        
        create_family("峨嵋派", 5, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/changjian")->wield();
}
// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一摇头，说道： 给我-
钱干什么？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N叹了口气，说道： 你-
好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

