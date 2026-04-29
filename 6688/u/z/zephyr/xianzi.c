#include <ansi.h>
inherit NPC;
inherit F_SAVE;

string *rnd_say = ({
    "你来到这里，找我有什么事情问吗？",
    "hi",
    "hello",
    "hmm",
    "wa...",
    "xixi",
    "wait...",
    "hohoho",
    "hehe",
    "ah..",
 });

object me = this_object();
void when_free();
varargs void drool(string msg, string who);

void create()
{
        set_name("葵花仙子", ({ "kuihua xianzi", "xianzi","wang tongtong"}) );
        set("long",CYN@LONG

她看上去顶多二十岁左右的样子，身穿白色的衣衫，
随风轻舞，直不若凡人。她容颜秀丽，一双乌溜溜的
大眼晶光粲烂，闪烁如星，流波转盼，灵活之极，似
乎能说话一般。发现你在看她，她调皮的冲你做了个
鬼脸
                ^_*

真不敢相信这个灵气十足，又可爱又淘气的小姑娘
就是葵花宫宫主，葵花仙子。

LONG NOR
         );

        set("gender", "女性" );
        set("title",CYN"葵花宫"HIY"宫主");
        set("nickname",HIG"影徒随我身"NOR);
        set("age",25);
        //set advanced skills

        set_temp("manashield",1);       
        set("str", 200);
        set("int", 200);
        set("cor", 200);
        set("cps", 200);                       
        set("per", 200);
        set("con", 200);

        set("atman", 20000);
        set("max_atman", 10000);

        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 200);
        set("kee", 10000);
        set("max_kee", 10000);
        set("gin", 10000);
        set("max_gin", 10000);
        set("sen", 10000);
        set("max_sen", 10000);

        set("mana", 20000);
        set("max_mana", 10000);

          set("combat_exp", 100000000);
                set_skill("music",250);
                set_skill("moqin",250);
                set_skill("force", 250);
        set_skill("parry", 450);
        set_skill("dodge", 450);
        set_skill("move", 450);
        set_skill("literate", 450);
        set_skill("perception", 450);
        set_skill("sword", 450);
        set_skill("mysterrier", 450);
        set_skill("dugu-jiujian", 450);
        set_skill("qiankun-danuoyi", 450);
        set_skill("taiji-shengong", 450);
        set_skill("stormdance", 450);

                map_skill("music","moqin");
                map_skill("dodge", "stormdance");
            map_skill("move", "mysterrier");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("sword", "dugu-jiujian");
        map_skill("force", "taiji-shengong");

                prepare_skill("music", "moqin");

                set_temp("apply/damage",100);
                set_temp("apply/armor",2000);
                set_temp("apply/armor_vs_force",3000);
                set_temp("apply/attack",100);
                set_temp("apply/defense",100);
                set_temp("apply/dodge",100);
                set_temp("apply/parry",100);
            set("chat_chance", 5);
            set("chat_msg", ({
                    (: when_free :),
                    (: drool :),
                    (: drool :),
            }));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
 (: perform_action, "move.hasten" :),
 (: perform_action, "move.sevensword" :),
        }) );

        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
    if( clonep() ) CHANNEL_D->register_relay_channel("chat");
               
}                          

                             
int killed_enemy(object ob)
{
        command("hmm");
}                 
void die()
{
   unconcious();
}
void revive()
{
   add("combat_exp", 10000);
        ::revive();
}
void when_free()
{
   int learn, i, level, level2;
   string *skills, skill;

   save();
   if ((learn = (query("potential") - query("learned_points"))) > 0) {
           skills = keys(query_skills());
           skill = skills[0];
           level = query_skill(skill, 1);
           for (i = 1; i < sizeof(skills); i++)
                   if ((level2 = query_skill(skills[i], 1)) < level) {
                           skill = skills[i];
                           level = level2;
                   }
           if (query("combat_exp") > 5000000)
                   set("combat_exp", 4999000);
           if (level > 250) {
                   add("learned_points", learn);
                   add("combat_exp", learn);
                   return;
           }
   
           message_vision("$N拿出一本发了黄的武学秘籍，认真研读起来。\n", this_object());
           while (learn--) {
                   if (query_skill(skill, 1) > 250)        return;
                   improve_skill(skill,  random(query_int()) );
                   add("learned_points", 1);
           }
   }       
   
   save();
}

int add_phrase(string who, string msg)
{
   msg = replace_string(msg, "?", "");
   msg = replace_string(msg, "？", "");
   msg = replace_string(msg, "？", "");
   msg = replace_string(msg, "!", "");
   msg = replace_string(msg, "！", "");
   msg = replace_string(msg, "啊", "");
   msg = replace_string(msg, "吗", "");
   msg = replace_string(msg, "耶", "");
   msg = replace_string(msg, "吧", "");

   if( msg!="" ) {
           if (sizeof(query_temp("memory/" + who)) > 10)
                   delete_temp("memory/" + who);
           add_temp("memory/" + who, ({ msg }));
           return 1;
   } else return 0;
}

string make_reply() { }

void relay_channel(object ob, string channel, string msg)
{
   string who, phrase;

   if( !userp(ob) || (channel != "chat") ) return;
   who = ob->query("name");

   // Don't process our own speech.
   if( ob==this_object() ) return;

   if( add_phrase(who, msg) &&     random(10) > 4 )
           drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
   string who, phrase;

   if( !userp(ob) ) return;
   who = ob->query("name");

   // Don't process our own speech.
   if( ob==this_object() ) return;

   if( add_phrase(who, msg) &&     random(10) > 4 )
           drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
   if( !userp(ob) ) return;

   switch(verb) {
   case "kick":
           if( random(10)<5 ) {
                   command("say 为什麽踢我？会痛耶！");
                   break;
           }
   case "poke":
           if( random(10)<10 ) {
                   command("say 别乱碰，男女授受不亲呢。");
                   break;
           }
   case "heihei":
           if( random(10)<10 ) {
                   command("say 你这个人好阴险啊！不象个好人！");
                   break;
           }
   case "smirk":
           if( random(10)<10 ) {
                   command("say 你干吗要冲着我傻笑啊？");
                   break;
           }
   case "thank":
           if( random(10)<10 ) {
                   command("say 不用谢，我也没帮上你什么。");
                   break;
           }
   case "joythank":
           if( random(10)<10 ) {
                   command("say 看你高兴的样子，我都替你高兴呢。");
                   break;
           }
   default:
           if( random(10)<5 )
                   command(verb + " " + ob->query("id"));
           else
                   drool();
   }
}

varargs void drool(string msg, string who)
{
   mapping mem;
   string *ob;

   mem = query_temp("memory");
   if( !mapp(mem) ) return;

   if( !msg || !who) {
           ob = keys(mem);
           who = ob[random(sizeof(ob))];
           msg = mem[who][random(sizeof(mem[who]))];
   }

   if( (strsrch(msg, "为什麽") >= 0) ) {
           if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
           switch(random(8)) {
           case 0: command("say " + who + "，你是在问我吗？"); break;
           case 1: command("say 关於" + msg + " ... "); break;
           case 2: command("say 呃 ... "); drool(); break;
           case 3: command("say 这个问题嘛 ...."); break;
           case 4: command("say " + who + "，知道这个问题的答案对你那麽重要吗？"); break;
           case 5: command("say " + msg + "？"); break;
           case 6: command("say " + who + "你能不能说清楚一点？"); break;
           case 7: command("say " + who + "，我不懂你问的问题"); break;
           }
   }
   else if( (strsrch(msg, "你") >= 0)
   ||      (strsrch(msg, "□") >= 0)
   ||      (strsrch(msg, "drooler") >= 0)
   ||      (strsrch(msg, "Drooler") >= 0)) {
           if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
           msg = replace_string(msg, "你", "我");
           msg = replace_string(msg, "□", "我");
           switch(random(10)) {
           case 0: command("say " + who + "，你是说" + msg + "吗？");      break;
           case 1: command("say 你确定" + msg + "？");     break;
           case 2: command("say " + msg + "跟你有什麽关系？");     break;
           case 3: command("say 嗯 ... " + who + "说得好"); break;
           case 4: command("say " + who + "你为什麽对" + msg + "这麽有兴趣？"); break;
           case 5: command("say 为什麽你认为" + msg + "？"); break;
           case 6: command("say 换个话题吧"); drool(); break;
           case 7: command("say 才怪"); break;
           case 8: command("say 不一定吧？"); break;
           case 9: command("say 有这个可能 ...."); break;
           }
   }
   else if( (strsrch(msg, "我") >= 0)) {
           if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
           msg = replace_string(msg, "我", "你");
           msg = replace_string(msg, "?", "");
           switch(random(8)) {
           case 0: command("say 你是说" + msg + "吗？"); break;
           case 1: command("say 真的？" + msg + "？");     break;
           case 2: command("say 如果" + msg + "，我能帮你什麽忙吗？");     break;
           case 3: command("hmm"); break;
           case 4: command("say 你认为" + msg + "？"); break;
           case 5: command("say 我有同感"); break;
           case 6: command("say 你说的「" + msg + "」我不能苟同"); break;
           case 7: command("say 有关「" + msg + "」的话题到此为止好吗？"); break;
           }
   }
   else if( (strsrch(msg, "葵花仙子") >= 0)) {
           if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
           msg = replace_string(msg, "我", "你");
           msg = replace_string(msg, "?", "");
           switch(random(3)) {
           case 0: command("say 为什么你会这样评价我呢？"); break;
           case 1: command("say 你为什么说" + msg + "？");     break;
           case 2: command("say 你说的「" + msg + "」我不能苟同"); break;
           }
   } 
   else {
           switch(random(20)) {
                   case 0: command("say 为什麽说" + msg + "?"); break;
                   case 1: command("say 「" + msg + "」是什麽意思？"); break;
                   case 2: command("say " + msg + "？"); break;
                   case 3: command("grin"); break;
                   case 4: command("smile"); break;
                   case 5: command("?"); break;
                   case 6: command("say ...."); break;
                   case 7: command("hmm"); break;
                   case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                   case 9: command("say 你怎麽知道" + msg + "?"); break;
                   case 10: command("say 刚刚" + who + "不是说了，" + msg); break;
                   case 11: command("say 我当然知道，" + msg); break;
                   case 12: command("say 然後呢？"); break;
                   case 13: command("say 真的吗？"); break;
                   case 14: command("say 我不这麽认为。"); break;
                   default:
                           break;
           }
   }
}
