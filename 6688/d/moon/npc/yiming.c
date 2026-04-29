/**************************************************************************/
// $Id: yiming.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("易明", ({ "yiming" , "yi" }) );

        set("nickname", HIM"翠燕剑客"NOR);
        set("gender", "女性");
        set("age", 30);
        set("long",
                HIR"易明,彩虹七剑之翠燕剑客。\n" NOR
                HIW"她武功高强，是武林中的后起之秀。\n" NOR
                HIW"她是红鹰剑客的妹妹\n" NOR
            );
        set("title",HIY "彩虹七剑" NOR);
        set("attitude", "peaceful");

        set("inquiry", ([
                "再生草庐主人": "嗯....我们就是向那里去的。\n",
                "云铿": "我不认识他....。\n",
                "麻衣客": "好像是夜帝的儿子。\n",
                "美貌姑娘": "有人看见他和一个麻衣客在一起. \n",
                "结婚": "前些天我看见再生草庐那里张灯结彩，好像有人要结婚。\n",
        ]) );

        set("str", 60);
        set("int", 24);
        set("cor", 30);
        set("cps", 60);
        set("per", 30);

        set("force", 14000);
        set("max_force", 7000);
        set("force_factor", 100);
       set("max_mana",10000);
       set("max_atman",10000);
        set("combat_exp", 7000000);
        set("score", 500000); 
       set("max_kee",8000);
       set("max_gin",5000);
       set("max_sen",5000);
       set("kee",8000);
       set("gin",5000);
       set("sen",5000);
//       set("armor_vs_force", 100);
//       set("armor", 100);
        set("env/wimpy", 10);
        
        set("chat_chance", 2);
        set("chat_msg", ({
                HIW"哥哥，听说江湖上出现了一个说话结结巴巴,身世很凄惨的美貌姑娘,不知道是谁的女儿\n" NOR,
                HIR"哥哥,前些天看见山上张灯结彩的,不知道是不是有人要结婚了.\n" NOR,              
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("perception", 200);
        set_skill("literate",200);
        set_skill("cuiyan-jianfa",250);
        set_skill("cuiyan-force",200);
        set_skill("cuiyan-zhangfa",250);
        set_skill("cuiyan-shenfa",250);
        set_skill("sword",300);

        set_skill("buddhism", 200);

        map_skill("unarmed", "cuiyan-zhangfa");
        map_skill("force", "cuiyan-force");
       map_skill("dodge","cuiyan-shenfa");
       map_skill("sword","cuiyan-jianfa");
       map_skill("parry","cuiyan-jianfa");
        setup();
        carry_object("/d/moon/obj/ccloth")->wear();
        carry_object("/d/moon/obj/csword")->wield();

}


