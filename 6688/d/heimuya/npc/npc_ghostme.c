// theimuya.c
//last modified by pock 1998.05.25
inherit NPC;
inherit F_QUEST;
#include <ansi.h>
void create()
{
        set_name("小夜子", ({ "xiao yezi","yezi","xiao" }) );

        set("gender", "无性" );
        create_family("日月神教",2,"长老");	
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR + GRN + "长老" + NOR );
        set("age", 45);
        set("long",@LONG
        他就是传说中东方不败的开山大弟子小夜子。他是日月神教的
创教元老之一。早年师承风雷堂主童百雄，一柄大锤使得出神入化，
早已青出于蓝。他与华山派的小师妹阿梅曾有一段美好的姻缘。
他们在西湖边上建了一所庄院-夜梅庄（就是后来的梅庄），极其别致。
        然而，随着各大门派围剿黑木崖以来，日月神教渐渐人才凋零，
教主东方不败潜心钻研葵花神功，不理教务，杨莲亭一手遮天，教中一
片乌烟瘴气，偌大的魔教眼看就要瓦解冰消。小夜子重出江湖，欲重振
魔教声威。但公道不在人心，是非在乎实力，以他一人之力难有作为。
郁郁不得志之下，深藏在他心底的邪气爆发了，他引刀自宫，硬生生散
去一身功夫，投到东方不败门下修习号称天下第一，令武林人士闻之色
变的辟邪剑法

LONG
        );
        set("inquiry", ([
                "自宫" : "往事不堪回首，劝君自好!\n",
        ]) );
        set("attitude", "peaceful");
        
        set("str", 38);
        set("int", 66);
        set("spi", 26);
        set("per", 30);
        set("cps", 30);
        
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 15);
        
        set("combat_exp",  2085193);
        
        set_skill("force", 160);
        set_skill("parry", 180);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("sword",180);
        set_skill("pixie-sword", 200);
        set_skill("kuihua-shengong", 180);
	set_skill("music",51);
	set_skill("qimen-bagua",70);
        
        map_skill("dodge", "kuihua-shengong");
        map_skill("force", "kuihua-shengong");
        map_skill("sword", "pixie-sword");
        map_skill("parry","pixie-sword");
        
        setup();
	carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/belt")->wear();
        carry_object("/obj/cloth")->wear();
}

void init()
{        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       
       add_action("give_quest", "quest");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	switch( random(3) )
       {
        case 0 :
	say("小夜子喃喃自语道: 欲练神功，必先自宫!\n");                               
        break;
	case 1 :
        command(" sigh");
	break;
        case 2 :
        say("小夜子狠狠地道：破巫师，把我逼上了自宫的道路上.\n");                                                             
        break;
	}
}
