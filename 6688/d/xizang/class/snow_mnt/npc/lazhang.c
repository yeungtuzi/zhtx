//
// /kungfu/class/xueshan/lazhang.c  拉章大法师
// by secret
// /d/xizang/class/snow_mnt/npc/lazhang.c

#include <ansi.h>

inherit NPC;
inherit F_QUEST;
inherit F_MASTER;

string ask_for_join();

void create()
{
        set_name("拉章大法师", ({ "lazhang dafashi", "lazhang",
                "dafashi", "fashi" }));
        set("long",@LONG
拉章大法师是雪山寺有道的高僧，对佛法有精深的研究。
他身穿一件黄色袈裟，头带僧帽。慈眉善目，似乎手无缚鸡之力。
LONG
        );
        set("title",HIY"大法师"NOR);
        set("gender", "男性");
        set("age", 51);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("max_kee", 4000);
        set("max_gin", 3500);
	set("max_sen", 3400);
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
        set("combat_exp", 1300000);
        set("score", 100000);
	set("shen", -20000);

        set_skill("literate", 120);
	set_skill("zang-buddhi", 120);
        set_skill("force", 100);
        set_skill("xiaowuxiang-gong", 100);
        set_skill("dodge", 120);
	set_skill("move", 110);
        set_skill("notracesnow", 110);
        set_skill("unarmed", 140);
        set_skill("nutrifux", 140);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 100);

        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("unarmed", "nutrifux");
        map_skill("parry", "nutrifux");
        map_skill("sword", "mingwang-jian");


        create_family("雪山寺", 3, "大法师");
        set("class", "lama");

        set("inquiry",([
                "修行"  : (: ask_for_join :),
                "入寺"  : (: ask_for_join :),
        ]));

        setup();

        carry_object(__DIR__"obj/y-jiasha")->wear();
        carry_object(__DIR__"obj/sengmao")->wear();

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("class") != "lama") {
                command("say 你先加入(join)本寺,我才能传你功夫。");
                ob->set_temp("pending/join_lama", 1);
                return;
        }
        if ((string)ob->query("family/family_name") != "雪山寺") {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "不如先跟可伦布师傅学习？");
                return;
        }
        command("smile");
        command("nod");
        command("say 你就随我学习佛法吧！");
        command("recruit " + ob->query("id"));

        ob->set("title",HIY"大喇嘛"NOR);
}

void init()
{
        add_action("do_join", "join");
        add_action("give_quest","quest");
}

string ask_for_join()
{
        object me;

        me = this_player();

        if( (string)me->query("class")=="lama" )
                return "你已经是喇嘛教徒了,不要开这种无聊玩笑.\n";
        me->set_temp("pending/join_lama", 1);
        return "你真的要加入(join)本寺,现在就作决定吧.\n";
}

int do_join()
{
        object me = this_player();

        if( !me->query_temp("pending/join_lama") )
                return 0;
        message_vision(
                "$N五体投地，恭恭敬敬地匍伏在拉章大法师面前。\n\n"
                "$n伸出手掌，在$N头顶轻轻地摩挲了几下，给$N行了受戒之礼.\n\n",
                me, this_object() );
        command("smile");
        me->set("class", "lama");
        return 1;
}

int accept_fight(object me)
{
        object ob;
        if(me->query_temp("weapon") || me->query_temp("secondary_weapon") ){
                if(!ob=present("jian", this_object())) {
                        ob=new(OBJ_DIR"weapon/changjian");
                        ob->move(this_object()); 
                }
                ob->wield();
                command("say 既然这位"+RANK_D->query_respect(me) +
                        "用兵刃,在下空手接招未免不敬.");
                return 1;
        }
        command("say 进招吧!");
        return 1;
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

