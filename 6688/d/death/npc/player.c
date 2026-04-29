//player.c 1998年2月17日 星期二, 02:25:47
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIW "玩家嘻嘻一笑：哟！你来了？\n\n" NOR,
        HIW "玩家盯了你一眼, 关切的问: 怎么搞的? 你也太不小心了。\n\n" NOR,
        HIW "玩家悄悄的向你嘀咕道:吃饭防噎,走路防跌, 别太张扬了。\n\n" NOR,
        HIW "玩家叹了口气: 被pk了?\n\n" NOR,
        HIW "玩家摇了摇头: 人心不古, 别把mud想得太好了, mud里什么人都有!\n\n" NOR,
        HIW "玩家怜惜的看着你: 还想玩吗?不想玩就先quit吧!\n\n" NOR,
        HIW "玩家泪流满面: mud害人不浅啊!\n\n" NOR,
        HIW "玩家神神秘秘的说: 其实死一次不见得是坏事!\n\n" NOR,
        HIW "玩家神秘兮兮的说: 四处走一走, 瞧一瞧吧!\n\n" NOR,
        HIW "玩家「啊」的一声: 你还想玩啊? 你真的还想玩啊?!!\n\n" NOR,
        HIW "玩家一本正经: 罢，罢，你走吧, 记住, 杀人者终被人杀!!\n\n"
                "你突然笼罩在一片奇异的蓝色辉光之下。\n\n" NOR,
});

void create()
{
        set_name("玩家", ({ "player" }) );
        set("long",
                "纵横天下「造谣大师」玩家, 他看起来约二十多岁。\n");
        set("attitude", "peaceful");
        set("chat_chance", 15);
        set("chat_msg", ({
//              (: this_object(), "random_move" :),
                "玩家故作严肃状，当他发现你正注视著他的时候，忍不住冲你嘻嘻一乐。\n",
                "玩家轻轻的替你擦干眼泪，柔声说道：损失的经验终会恢复, 你的仇也终能得保。\n",
                "玩家轻轻的叹道: 经验那么重要吗? 仇恨那么难忘吗?\n"
        }) );
        set("age", 217);
        set("combat_exp", 20000);
        set("max_gin", 900);
        set("max_kee", 900);
	set("apply/parry",500);
	set("no_get",1);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object())
        ||      wizardp(previous_object()) ) return;
        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) ) return;

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 15, ob, stage );
                return;
        } else
                ob->reincarnate();

        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
        ob->move(REVIVE_ROOM);
        message("vision",
                "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(ob), ob);
}
