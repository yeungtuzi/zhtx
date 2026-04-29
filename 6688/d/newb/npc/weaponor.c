///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

// weaponor.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("兵器贩子", ({ "weaponor","兵器贩子"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "卖兵器的是个中年人，满脸伤疤。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 60);

        set("inquiry", ([
                "兵器屋" : "本店专卖各种长短兵器",
        ]) );

        set("vendor_goods", ([
                 "/obj/weapon/bamboo_sword":6,
                 "/obj/weapon/whip":6,
                 "/obj/weapon/longsword":3,
                 "/obj/weapon/dart":6,
                 "/obj/weapon/shield":6,
//               "/obj/weapon/sixhammer":6,
 //            "/obj/weapon/thin_sword":6,
                 "/obj/weapon/dagger.c":6,
                 "/obj/weapon/staff.c":6,
                 "/obj/weapon/blade.c":6,
                 __DIR__"obj/bow":20,
                 __DIR__"obj/tiejia":6,
        ]) );

        set("shen_type",-1);
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
        add_money("silver", 5);
        add_money("coin", 300);
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


}

void greeting(object ob)
{
                int exp;
                if( !ob || environment(ob) != environment() ) return;
                exp=ob->query("combat_exp");

        switch( random(5) ) {
                case 0:
                        say( "兵器贩子道：这位"
                                + RANK_D->query_respect(ob)
                                + "，自个儿挑一件称手的兵器吧\n");
                        break;
                case 1:
                        say( "兵器贩子突然间出了神，好象想起了他的往事\n");
                        break;
        }

        if(exp<50000) {
        tell_object(ob,YEL"兵器贩子说道：欢迎惠顾！在这儿可以买到各种兵器和防具哦。\n"
        +"用指令"HIW+" list "NOR+YEL"可以看到商品列表。用指令"HIW+" buy <物品> from weaponor "NOR+YEL"就可以买到了，\n"
        +"你可以用"HIW+" wield <武器> "NOR+YEL"来装备武器，用"HIW+" unwield <武器> "NOR+YEL"来解除装备。\n"
        +"另外，匕首是一种特殊的兵器，你可以同时装备一个匕首和一种其他武器，来增加伤害力。\n"
        +"防具可以用指令"HIW+" wear <防具> "NOR+YEL"来装备。\n"
        +"有关战斗的情况你可以用"HIW+" help combat "NOR+YEL"来获得更多帮助。\n"NOR);

                }
}


