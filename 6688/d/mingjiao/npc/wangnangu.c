/*
	银叶的秘密：
	1. 完成dayisi的秘密。
	2. 向谢逊打听yinye
	3，向hu qingniu打听yinye死因。
	3. 向金花打听yinye,同意追查死因。
	4. 向yang xiao打听其独门毒药。
	5。找 hu qingniu鉴定毒药
	6。和范遥对质，杀之。
	7。找金花报告，化解和胡青牛的冤仇。
	8。向hu qingniu报告。得到奖励。
*/

// saint.c
// written by tang
//1998.5.9

#include <ansi.h>

inherit NPC;
//inherit F_CONDITION;

void use_poison();

void create()
{
        set_name(HIY"王难姑"NOR, ({ "wang nangu","wang" }) );
        set("title",HIC"毒仙"NOR);
        set("nickname", HIR"药不死人"NOR);
        set("gender", "女性");
        set("age", 50);
        set("long", 
"王难姑是胡青牛的同门师妹，她总是不服丈夫的医技能胜过自己，因此总是
和丈夫闹别扭，其实他们情深意重，是一对欢喜冤家。\n");

        set("attitude", "peaceful");

        set("str", 100 + random(16));
        set("cps", 100 + random(16));
        set("int", 100 + random(16));
        set("cor", 100 + random(16));
        set("con", 100 + random(16));
        set("spi", 100 + random(16));
        set("per", 10 + random(16));
        set("kar", 100 + random(16));
                                        
        set("kee",2000);
        set("max_kee", 2000);
        set("gin",1000);
        set("max_gin", 1000);
        set("sen",1000);
        set("max_sen", 1000);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 100);
        set("max_mana", 100);

        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);

        set("combat_exp", 5000000);
	set("shen_type",-1);

        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("throwing", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);                            
        set_skill("move", 200);
        set_skill("strike",200);
        set_skill("dugong", 200);
        set_skill("literate", 200);

        set_skill("tangmen-xinfa", 200);
        set_skill("tangshi-jian", 200);
        set_skill("mantian-huayu", 200);
        set_skill("taxue-wuhen", 200);
        set_skill("tangmen-duzhang",200);

        map_skill("dodge", "taxue-wuhen");
        map_skill("move", "taxue-wuhen");
        map_skill("force", "tangmen-xinfa");
        map_skill("sword", "tangshi-jian");
        map_skill("parry", "tangshi-jian");   
        map_skill("strike", "tangmen-duzhang");
        map_skill("throwing", "mantian-huayu");

        prepare_skill("strike","tangmen-duzhang");

        set_temp("apply/defense", 100);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                "王难姑右手轻摆，脸上似笑非笑，似怒非怒。\n",
                (: use_poison :),              
        }) );

        setup();
        carry_object(__DIR__"obj/xuehama");
        carry_object(__DIR__"obj/wangguo");
}

void use_poison()
{
        // 2026-04-30: unused variable commented out
        // object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp")/2 )
        {
                tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
                switch(random(3))
                {
                        case 0:
                                ob->apply_condition("tm_poison", random(20)+ob->query_condition("tm_poison"));    
                                break;
                        case 1:
                                ob->apply_condition("rose_poison", random(20)+ob->query_condition("rose_poison"));    
                                break;
                        case 2:
                                ob->apply_condition("ninemoonpoison", random(20)+ob->query_condition("ninemoonpoison"));    
                                break;
                }
        }
        return ;
}

