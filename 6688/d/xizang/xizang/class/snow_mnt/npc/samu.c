//
// by secret
// /d/xizang/class/snow_mnt/npc/samu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("萨木大法师", ({ "samu dafashi", "dafashi" }));
        set("long",@LONG
萨木大法师是雪山寺有道的高僧，对佛法有精深的研究。
他身穿一件黄色袈裟，头带僧帽。一副若有所思的样子。
LONG
        );
        set("title", HIY "大法师" NOR);
        set("gender", "男性");
        set("age", 47);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("cor", 30);
        set("max_kee", 2500);
        set("max_gin", 2000);
	set("max_sen", 2000);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);
        set("combat_exp", 1200000);
        set("score", 100000);
	set("shen", -10000);

        set_skill("literate", 80);
	set_skill("zang-buddhi", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang-gong", 100);
        set_skill("dodge", 120);
	set_skill("move", 130);
        set_skill("notracesnow", 100);
        set_skill("unarmed", 120);
        set_skill("nutrifux", 100);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 100);

        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("unarmed", "nutrifux");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");


        create_family("雪山寺", 3, "大法师");
        set("class", "lama");

        setup();

        carry_object(OBJ_DIR"weapon/changjian")->wield();
        carry_object(__DIR__"obj/y-jiasha")->wear();
        carry_object(__DIR__"obj/sengmao")->wear();
        add_money("silver",5);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("class") != "lama") {
                command("say 我只收喇嘛教徒作弟子。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺") {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
        }

        command("smile");
        command("nod");
        command("say 你就随我学习佛法吧！");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY"大喇嘛"NOR);
}
