// zhaomin.c
// by yeung
// 1998/07/19

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;

int rescue_me(object ob);

void create()
{

        set_name("赵敏", ({ "zhao min", "zhao", "min" }) );
        set("title", HIG"绍敏郡主"NOR);
        set("gender", "女性" );
        set("age", 20);
        set("int", 100);
        set("per", 200);
        set("long",@LONG
        赵敏是前朝绍敏郡主，后来随张无忌来到了光明顶。这时候她
身着嫩绿绸衫，左手持杯，右手执书，正在坐着看书饮茶。
LONG
                );
        set("chat_chance", 1);
        set("chat_msg", ({
                "一股淡淡的幽香从赵敏身上随微风飘过来，你不禁心中一荡。\n",                
                "赵敏轻轻地把书翻过去一页，品了一口茶。\n",
        }) );

        set("inquiry", ([
                "张无忌": "......\n",
                "name": "你也知道我呀，我的真名是敏敏特穆尔，赵敏是我自己取的汉人名字。\n",
        ]) );
        set("attitude", "peaceful");
        set("shen",-500000);
        set("max_gin",3000);
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_force",4000);
        set("max_mana",300);
        set("max_atman",300);
        set("force",8000);
        set("mana",3000);
        set("atman",3000);
        set("force_factor",250);
        
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);        
        set_skill("literate", 250);
        set_skill("sword",200);
        set_skill("strike",200);

        set_skill("essence-sword", 200);
        set_skill("lighting-sword", 150);
        set_skill("bat-steps", 200);
        set_skill("moni-xinfa", 200);
        set_skill("xuanming-shenzhang", 200);         
        
        map_skill("force", "moni-xinfa");
        map_skill("sword", "essence-sword");
        map_skill("parry","essence-sword");
        map_skill("dodge","bat-steps");
        map_skill("move","bat-steps");
        map_skill("strike","xuanming-shenzhang");
        prepare_skill("strike","xuanming-shenzhang");

        set("combat_exp", 5000000);
        create_family("明教",34,"教主夫人");



        setup();

        carry_object(__DIR__"obj/fakeskysword")->wield();
}

void init()
{
        object ob;

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
        message_vision("$N冲着$n轻轻一笑：这位"+RANK_D->query_respect(ob)+"到小女子房中来，有何指教？\n",this_object(),ob);
}

int rescue_me(object ob)
{
        object room,sword,enemy,me,fake_sword;
        
        me = this_object();
        room = environment(ob);
        if( !objectp(room) )
                return 1;
        
        message_vision("$N突然放下书和茶杯，站了起来。\n一位美丽少女急匆匆地向南离开。\n",me);
        
        enemy = ob->select_opponent();
        if( !objectp(enemy) )
                return 1;
        
        me->move(room); 
        fake_sword = present("yitian jian",me);
        if( sword=present("yitian jian",ob) )
        {
                sword->move(me);
                if( objectp(fake_sword) )
                {
                        fake_sword->unwield();
                        destruct(fake_sword);
                }
                sword->wield();
        }
        tell_room(room,HIC"\n\n突然之间，一道倩影电射而至，赵敏从张无忌腰间抽出倚天剑，闪电般扑来！

\n\n"NOR);
        me->add_temp("apply/damage",200);       
        me->set("cor",200);
        me->map_skill("sword","lighting-sword");
        me->kill_ob(enemy);
        
        COMBAT_D->do_attack(me,enemy,me->query_temp("weapon"));
        if( enemy->query("eff_kee") < 0 || enemy->is_ghost() ) return 1;
        COMBAT_D->do_attack(me,enemy,me->query_temp("weapon"));
        if( enemy->query("eff_kee") < 0 || enemy->is_ghost() ) return 1;
        COMBAT_D->do_attack(me,enemy,me->query_temp("weapon"));
        
}

void attempt_apprentice(object ob)
{
        object me  = this_object();

        mapping ob_fam;
        mapping my_fam  = me->query("family");
         if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")
        {
                 command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？

");
                return 0;
        }

        if (ob->query("gender")!="女性") {
                command("say 我只收女弟子，阁下可以拜无忌。");
                return 0;
        }
        if ((ob->query("per")<24) || (ob->query("int")<20)
                || (ob->query("wil")<20)) { 
                command("shake");
                command("say 以你这样的天赋，做我的弟子还差了些。");
                command("sigh");
                return 0;
        }
        if (ob->query_skill("moni-xinfa", 1) < 100) {
                command("shake");
                command("say 你的摩尼心法修为还太浅,还是先找几位法王苦练之后再来吧！");
                return 0;
        }
        command("say 好，我就收下你了");
        command("say 再接再砺！");
         command("say 日后必要跟从张大教主，光复本教！"); 
         command("say 恭喜你荣任明教光明圣使！"); 
        command("recruit " + ob->query("id"));
        ob->set("title","明教"+GRN"光明使者"NOR);
        return;
}


