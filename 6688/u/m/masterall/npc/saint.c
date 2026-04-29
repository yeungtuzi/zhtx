// saint.c
// written by tang
//1998.5.9

#include <ansi.h>

inherit NPC;
//inherit F_CONDITION;

void use_poison();

void create()
{
        set_name(HIY"不痴大师"NOR, ({ "buchi dashi","buchi","dashi" }) );
        set("title",RED"圣人"NOR);
        set("nickname", HIR"万毒尊者"NOR);
        set("gender", "男性");
        set("age", 70);
        set("long", 
"一个独眼老僧，据说医术高超，善于解毒，没有人知道他来自何方，
也没有人知道他师出何门，有人说他是『毒手药王』的师弟，也有人
认为他是“五毒门”用毒高手，但大多数人认为他是“唐门”的长老，
为了研究天下奇毒，在江湖中给江湖朋友疗毒，但他自己订了一个规
矩：即中毒者必须送给他神兵利刃，否则打死他也不愿意给人疗毒。\n");

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

        set("combat_exp", 10000000);
        set("score", 90000);

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

        set_temp("apply/defense", 300);

        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
                }) );

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                "不痴大师左手一扬，从袖中发出一阵青烟。\n",
                (: use_poison :),              
        }) );

        setup();

        carry_object("/d/tangmen/obj/huixuanbiao")->wield();
        carry_object("/d/shaolin/obj/cloth")->wear();
}

void init()
{
}

int accept_object(object who, object ob)
{
        string *conditions=({}),*list,arg;
        int i;
        object drug;

        if( this_object()->is_busy() )
                return notify_fail("老衲正在给人解毒，施主等一下吧。");

        if( ob->query("tactic_bonus") )
        {
                command("say 阿弥陀佛，善哉善哉！\n");
                message_vision("这位施主为国杀敌，屡建功勋，可喜可贺！\n",who);
                who->add("tactic_exp",ob->query("tactic_bonus"));
                return 1;
        }

        if( ob->query("weapon_prop/damage") < 200 )      return 0;

        if( (int)who->query("eff_kee") < (int)who->query("max_kee") / 5 )
                return notify_fail( "这位甚至施主已经受伤过重，经受不起老衲的真气震荡！\n");

        list = get_dir("/daemon/condition/");

        i = sizeof(list);
        while( i-- )
        {
                arg = list[i];
                if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                {
                        conditions += ({arg[0..strlen(arg)-3]});
                        if( who->query_condition(arg[0..strlen(arg)-3]) )
                                who->set_temp("marks/有毒",1);
                }
        }
        
        if( who->query_condition("super_poisons") )
        {
                who->delete_temp("marks/有毒");
                return notify_fail("这位施主中的毒太奇怪，老衲也不会解。");
        }
/*
        if( !(who->query_temp("marks/有毒")) )
        {
                command("say 这位施主，你体内没有中毒。\n");
                if( query("drug") > 2 )
                        return notify_fail("你来晚了，我的还灵丹已经散发完毕啦。\n");
                add("drug",1);
                drug = new("/obj/npc/obj/drug");
                drug->move(who);
                command("say 阿弥陀佛，善哉善哉！\n");
                command("say 这位施主是来要还灵丹救人的吧，老衲这还有一颗，\
你拿去吧。\n");
                return 1;
        }
*/
        tell_object(who,"善哉，善哉！这位施主太客气了，这样吧，
老衲别无长技，就给施主解了体内的毒吧。\n\n");

        message_vision(
                HIG "$N"+HIG"坐了下来运起内功给$n解毒....\n\n"NOR,this_object(),who );
        message_vision(HIG"过了不久，$N"+HIG"额头上冒出豆大的汗珠，从$n手指尖滴出一缕黑血，

黑血渐渐由黑转红...\n\n"NOR,this_object(),who);

        this_object()->start_busy(10);

        i = sizeof(conditions);
        while(i--) 
        {
                if( who->query_condition(conditions[i]) > 0 )
                        who->apply_condition(conditions[i],0);
        }
        
        if( who->query_condition("fushi-du") )
        {
                who->clear_condition("fushi-du");
        }
        if( who->query_condition("iceshock") )
        {
                who->clear_condition("iceshock");
        }
        if( who->query_condition("ninemoonpoison") )
        {
                who->clear_condition("ninemoonpoison");
        }
        if( who->query_condition("sheng_si") )
        {
                who->clear_condition("sheng_si");
        }
        if( who->query_condition("rose_poison") )
        {
                who->clear_condition("rose_poison");
        }
        who->delete_temp("marks/有毒");
        tell_object(who,HIC"好啦，这位施主体内的毒已经解啦！！\n"NOR);

        return 1;
}

void use_poison()
{
        object *enemy, ob;
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

