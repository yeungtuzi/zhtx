#include <ansi.h>

inherit NPC;

string ask_lmsj();

void create()
{
        set_name("段誉", ({"duan yu", "duan"}));
        set("title", "大理王子");
        set("nickname", MAG"向来痴"NOR);
        set("age", 20);
        set("gender", "男性");
        set("rank_info/respect", "段公子");
        set("long", @LONG
他是大理镇南王之子，奉命千里迢迢来西夏求婚，不过他对这个驸马一点
兴趣也没有。
LONG);
        set("attitude", "peaceful");

        set("str", 28);
        set("dex", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("cor", 23);
        set("max_kee", 9999);
        set("max_sen", 999);
        set("max_gin", 999);
        set("max_force", 9999);
        set("force", 9999);
        set("force_factor", 200);

        set("combat_exp", 800000);
        set("shen_type", 1);

        set("inquiry", ([
                "name": "你既然知道我是段公子，怎么不知道我叫段誉？",
                "六脉神剑": (: ask_lmsj :),
        ]));

        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor_vs_force", 150);

        set_skill("dodge", 200);
        set_skill("move", 220);
        set_skill("parry", 100);
        set_skill("finger", 180);
        set_skill("force", 200);
        set_skill("literate", 190);
        set_skill("qi", 170);
        set_skill("music", 120);

        set_skill("lingboweibu", 220);
        set_skill("beiming-shengong", 200);
        set_skill("liumai-shenjian", 180);

        map_skill("finger", "liumai-shenjian");
        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingboweibu");
        map_skill("move", "lingboweibu");
        
        prepare_skill("finger", "liumai-shenjian");

        setup();

        carry_object(__DIR__"obj/jinpao")->wear();
        carry_object(__DIR__"obj/gold_belt")->wear();
}

string ask_lmsj()
{
        object me = this_player();
     if( me->query("family/family_name") != "逍遥派")
     return "你非逍遥派门下弟子，问这个干什么！\n";

     if( me->query("max_force") < 5000 )
     return "阁下内力太低，强练六脉神剑反而会伤及自身！\n";

     if( me->query("skill_mark/liumai-shenjian")  )
     {       
     return "你不是已经掌握了六脉神剑其中要诀了么？自己努力修炼吧！";                      
     }
        command("say 我这六脉神剑也是时灵时不灵的。");
                tell_object(me, "你听了段誉的讲解，似懂非懂。\n");      
                me->improve_skill("liumai-shenjian", 10);
                me->set("skill_mark/liumai-shenjian",1);
}

