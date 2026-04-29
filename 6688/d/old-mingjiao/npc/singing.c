// singing.c

#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
        set_name("低唱", ({ "singing" }) );
        set("gender", "女性" );
        set("long", "这是一个美丽的女子，大约三十多岁。
美丽的脸上总带着微微的笑容，让人觉得亲切。当年明教的人，谁
不记得这个可爱的小低唱呢？\n");
        set("attitude", "friendly");
        set("class","mingjiao");

        set("age", 32);
        set("str", 33);
        set("cor", 35);
        set("cps", 30);
        set("per", 30);

        set("max_force", 1700);
        set("force", 2000);
        set("force_factor", 30);
        set("max_mana", 410);
        set("mana", 410);
        set("max_atman", 160);
        set("atman", 160);

        set("nickname", "小嘻嘻");
        set("rank_info/respect", "好姐姐");

        set("chat_msg", ({
                CYN "低唱嘻嘻的笑了几声。\n" NOR,
                CYN "低唱道了个万福。\n" NOR,
        }) );

        create_family("明教",20, "护法");

        set("combat_exp", 1000000);
        set("score", 200000);

        set_skill("dodge",110);
        set_skill("force",150);
        set_skill("iron-cloth",100);
        set_skill("literate", 115);
        set_skill("magic", 41);
        set_skill("move", 51);
        set_skill("parry", 120);
        set_skill("qimen-bagua", 71);

        set_skill("spells", 41);
        set_skill("strike", 60);
        set_skill("sword", 120);

        set_skill("jiuyang-shengong", 180);
        set_skill("qiankun-danuoyi", 100);
        set_skill("shenghuo-shengong", 150);
        set_skill("taxue-wuhen", 130);
        set_skill("xiaoyao-zhang", 100);

        map_skill("dodge", "taxue-wuhen");
        map_skill("force", "jiuyang-shengong");
        map_skill("iron-cloth", "jiuyang-shengong");
        map_skill("move", "taxue-wuhen");
        map_skill("parry", "shenghuo-shengong");
        map_skill("strike", "xiaoyao-zhang");
        map_skill("sword", "shenghuo-shengong");


/*
        set("inquiry", ([
                "帮忙": (: ask_me :)
        ]) );
*/
        set("env/wimpy", 30);
        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/gangjian")->wield();
}

int accept_order(object me, string verb)
{
        if( (string)me->query("id") == (string)query("boss_id") ) {
                switch(verb) {
                        case "follow":
                                return 1;
                        case "hit":
                                return 1;
                        case "guard":
                                return 1;
                        case "ask":
                                return 1;
                        case "enforce":
                                return 1;
                        case "wield":
                                return 1;
                        case "unwield":
                                return 1;
                        default:
                                command("say 我想，这样不太好吧。我就不做了。\n");
                                return 0;
                }
        }
        return 0;
}

int accept_info(object me, string command)
{
        return (string)me->query("id") == (string)query("boss_id");
}

int ask_me()
{
        object me = this_object();
        if( query("boss_id") ) {
                command("say 对不起，我正忙着呢。");
                return 0;
        }

        if( this_player()->query("class") != "mingjiao" ) {
                command("say 对不起，明教的朋友们正找我呢。");
                return 0;
        }

        set("boss_id", this_player()->query("id"));
        remove_call_out("end_duty");
        call_out("end_duty", 600, me );
        command("say 好吧" + RANK_D->query_respect(me) +"！同门有事我自当尽力！\n");
        command("xixi");
        return 1;
}

void end_duty(object me)
{
        command("tell " + query("boss_id") + " 我还有点急事，下次见。");
        command("fu");
        command("wave");
        delete("boss_id");
        command("halt");
        command("guard cancle");
        command("follow none");
        me->move("wuqishi");
}


