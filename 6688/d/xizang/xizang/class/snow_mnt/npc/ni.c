// /d/xizang/class/snow_mnt/npc/ni.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("玄霜", ({ "xuan", "ni" ,"xueshan shenni", "xuanshuang" }));
        set("nickname", HIY "雪山神尼" NOR);
        set("long",@LONG
她是雪山寺的副住持,人称雪山神尼.清修已久,性格多少有些孤僻.她只肯
收本寺女弟子,男弟子最好少找她的麻烦.
LONG
        );
        set("gender", "女性");
        set("age", 65);
        set("attitude", "friendly");
        set("str", 20);
        set("int", 40);
        set("con", 30);
        set("max_kee", 4500);
        set("max_gin", 4000);
	set("max_sen", 4000);
        set("force", 6000);
        set("max_force", 6000);
        set("force_factor", 110);
        set("combat_exp", 5000000);
        set("score", 500000);
	set("shen", -500000);

	set_skill("zang-buddhi", 240);
        set_skill("force", 240);
        set_skill("xiaowuxiang-gong", 240);
        set_skill("dodge", 240);
        set_skill("notracesnow", 240);
        set_skill("unarmed", 200);
        set_skill("nutrifux", 230);
        set_skill("parry", 200);
        set_skill("sword", 220);
        set_skill("mingwang-jian", 220);
        set_skill("literate", 100);
	set_skill("move", 240);

        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("unarmed", "nutrifux");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        map_skill("move", "notracesnow");

        create_family("雪山寺", 2, "副住持");
        set("class", "lama");
	set("has_book", 1);

        setup();

        carry_object(OBJ_DIR"weapon/changjian")->wield();
        carry_object(__DIR__"obj/r-jiasha")->wear();

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "女性") {
        	command("say 我不收男弟子。");
		if (random(ob->query("per")) < 25)
			fight_ob(ob);
        	command("say 快走,别惹我生气!");
                return;
	}
	if ((string)ob->query("class") != "lama") {
        	command("say 我只收喇嘛教徒。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
	}
        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
	}
        if ((int)ob->query_skill("xiaowuxiang-gong", 1) < 100) {
                command("say 你的功夫太差,我帮不了你。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是多去钻研一下小无相功秘籍吧.");
		add_action("do_ask", "ask");
                return;
        }
	command("say 好,那我就收下你,希望你能光大本寺,护法卫道.");
        command("recruit " + ob->query("id"));
	ob->set("title",HIY"大法师"NOR);
}

int do_ask(string arg)
{
	object ob, me;
	if (!arg || (arg!="小无相功秘籍" && arg!="秘籍" && arg !="book"))
		return notify_fail("你想要什么?");
	me=this_player();
	if(me->query_kar()<random(30)) {
		command("say 你福缘不厚,并非有缘习得高深内功之人");
		command("sigh");
		return 1;
	}
	if(me->query_int()<random(40)) {
		command("say 你天资鲁钝,难以领悟高深内功");
		command("sigh");
		return 1;
	}
	if(!query("has_book")) {
		command("say 你来晚了,秘籍已经传与别人.");
		command("sigh");
		return 1;
	}
	command("say 好,这本秘籍就传给你,希望你能早日领悟.");
	ob=new(__DIR__"obj/miji");
	ob->move(me);
	add("has_book", -1);
	return 1;
}

//void reset()
//{
//	::reset();
//	set("has_book", 1);
//}
