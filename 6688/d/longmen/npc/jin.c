// waiter.c
// the coolest one!

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name(HIY"金湘玉"NOR, ({ "jin xiangyu" }) );
        set("gender", "女性" );
        set("title", HIC"龙门客栈"HIG"老板娘"NOR);
        set("nickname", HIM"桃花夫人"NOR);
        set("age", 34);
        set("long", @LONG
    她就是龙门客栈的老板娘。她一身披红挂绿，行动招摇，言语风骚。
虽已过花容之季，却不失风情，举手投足间尽显女人妖媚的厉害角色。看
她的眼神，秋波流荡，看她的举止，风韵十足。尽管是在塞外荒僻之处，
这家店还是被她打理得井井有条，不少中原人士不远千里而来，为的就是
能够欣赏一下她那惊世骇俗的艳色。
LONG
        );

        set("combat_exp", 50000000);
        set("max_force", 15000);
        set("force", 30000);
        set("force_factor", 500);
        set("per",100);

        set("attitude", "friendly");

        set("vendor_goods", ([
 //               __DIR__"obj/nuomi": 1,
 //               __DIR__"obj/xigua": 1,
                "/obj/example/wineskin": -1,
                "/obj/example/dumpling": -1,
                "/obj/example/chicken_leg": -1,
        ]) );

        set_temp("apply/damage", 1000);
        set_temp("apply/armor", 1000);
        set_temp("apply/armor_vs_force", 1000);

        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("move", 400);
        set_skill("taiji-shengong",400);
        set_skill("claw",400);
        set_skill("yin-gong", 400);

        map_skill("force", "taiji-shengong");
        map_skill("parry", "yin-gong");
        map_skill("dodge", "yin-gong");
        map_skill("move", "yin-gong");
        map_skill("claw","yin-gong");
        
        prepare_skill("claw","yin-gong");

        setup();
        carry_object("/d/longmen/obj/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
        add_action("do_look", "look");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "金湘玉盈盈万福，说道：“这位" + RANK_D->query_respect(ob)
                                + "，奴家这厢有理了。”\n");
                        break;
                case 1:
                        say( "金湘玉将纤纤玉手往货价上一指，说道：“这位" + RANK_D->query_respect(ob)
                                + "请随便看看，这里的货有不少可是稀世珍品哦。”\n");
                        break;
                case 2:
                        say( "金湘玉用挑逗的目光环顾着四周，说道：这位“" + RANK_D->query_respect(ob)
                                + "还想要别的什么东西吗，奴家这里可是要什么就有什么呐。”\n");
                        break;
        }
}

int do_look(string arg)
{
        if (arg == "jin xiangyu") {
                set("env/attack", 1);
                set("force_factor", 0);
                set("force", 0);
                set("max_force", 0);
                set("combat_exp", 0);
                set_temp("apply/damage", 0);
                "/cmds/std/look"->look_living(this_player(), this_object());
                set("env/attack", 50);
                set("force_factor", 500);
                set("force", 30000);
                set("max_force", 15000);
                set("combat_exp", 50000000);
                set_temp("apply/damage", 1000);
                return 1;
        }
}

