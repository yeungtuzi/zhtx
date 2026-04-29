
#include <ansi.h>

inherit NPC;
string ask2();

void create()
{
        set_name("郭靖", ({"guo jing", "guo", "jing"}));
        set("nickname", HIG "侠之大者" NOR);
        set("title",HIC "北  侠" NOR);
        set("gender", "男性");
        set("age", 30);
        set("long", 
                "他就是名震天下的大侠郭靖，是历史上武林中人人称道的侠之大者。\n");
        set("attitude", "peaceful");
        
        set("str", 100);
        set("int", 10);
        set("con", 100);
        set("dex", 100);
        set("fav", 15);
        set("per", 100);
        set("bln", 100);
        set("cor", 100);
        set("cps", 100);

        set("no_get",1);

        set("chat_chance", 1);
/*        set("chat_msg", ({
                "洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
                "洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来岳阳看看。”\n",
                "洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
              (: random_move :),
        }));
*/
        set("inquiry", ([
              "左右互搏": (: ask2 :),
                "青竹林" : "东北西北东西北。\n",
                "丐帮" : "东北西北东西北。\n",
                "拜师" : "你可以去东城门的我帮总舵拜鲁有脚。\n",
        ]));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "strike.hubo" :)
        }) );

        set("kee", 10000);
        set("max_kee", 10000);
        set("gin", 5000);
        set("max_gin", 5000);
        set("sen", 5000);
        set("max_sen", 5000);
        set("atman", 5000);
        set("max_atman",5000);
        set("force", 20000);
        set("max_force", 10000);
        set("mana", 5000);
        set("max_mana", 5000);
        set("force_factor", 500);
        set("combat_exp",100000000);
        set("score", 200000);
        set("shen",100000000);
         
        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 400);    // 混天气功
        set_skill("strike", 400);
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("dodge", 400);             // 基本躲闪
        set_skill("xiaoyaoyou", 400);        // 逍遥游
        set_skill("parry", 400);             // 基本招架
        set_skill("staff", 400);             // 基本棍杖
        set_skill("dagou-bang", 400);        // 打狗棒法
        set_skill("begging", 400);           // 叫化绝活
        set_skill("checking", 400);          // 道听途说

        set("zuoyou-hubo", 1);
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang"); 
        set("skill_mark/dagou-bang",1);
        
        create_family("丐帮", 18, "弟子");
        setup();
        
//        carry_object(__DIR__"yuzhu_zhang")->wield();
//        carry_object(__DIR__"jiaohuaji");
}

string ask2()
{mapping fam;
        object me=this_player();
     if( me->query("zuoyou-hubo")  )
     {       
     return "你不是已经学会左右互搏了么？自己努力修炼吧！";         
     }
        if (this_player()->query("family/family_name") != "丐帮" && this_player()->query("family/family_name") != "少林派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        else
        {
        message_vision("郭靖说道：“好吧，我就教你左右互搏吧。”\n",me);
        message_vision("郭靖说道：“这左右互搏本是周伯通周大哥教给我的。”\n",me);
        message_vision("郭靖说道：“需要修习者能够分心二用，你得多下点功夫才行啊！”\n",me);
        if (me->query_skill("xianglong-zhang",1)<180)               
        { message_vision("$N练了半天，还是没练会。”\n",me);
        return "也许是你的降龙十八掌不够纯熟，静不下心来练吧。\n";}
        message_vision("$N练了半天，学会了左右互搏之技。\n",me);
        me->set("zuoyou-hubo",1);
        return "如果让我发现你在江湖上为非作歹，那我决不轻饶！！\n去吧，记得一定要行侠仗义，才不负我对你的希望！\n";
        }
}


