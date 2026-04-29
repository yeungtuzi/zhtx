// /obj/toy/noname.c
// 无名花

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("无名花", ({ "noname flower", "flower" }));
	set_weight(20);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "这是一朵你叫不上名字的小花,好象有剧毒!\n");
		set("unit", "朵");
		set("value", 40);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("food_supply", 3);
	}
}

int eat_tonic()
{
	object me;
	int i, level;
	write("你实在饿极了,吞下一朵无名花.\n");
	level = random(20);
	i = random(10);
	if (i < 5) level = -1 * level;
	i = random(3);
	me = this_player();
	me->apply_condition("noname",me->query_condition("noname")+random(10));
	switch ((int)i) {
		case 0 : //atman
		me->add("atman", level);
		if((int)me->query("atman")<= 0) me->set("atman",0); 
                if((int)me->query("atman")>=(int)me->query("max_atman")*2){
                me->add("max_atman", 1);
                write("你的灵力提高了! \n");
		break;
		case 1 : //force
		me->add("force", level);
		if((int)me->query("force")<= 0) me->set("force",0);
		if((int)me->query("force")>=(int)me->query("max_force")*2){
		me->add("max_force", 1);
		write("你的内力提高了! \n");
		break;
                case 2 : //mana
		me->add("mana", level);
		if((int)me->query("mana")<= 0) me->set("mana",0);
		if((int)me->query("mana")>=(int)me->query("max_mana")*2){
                me->add("max_mana", 1);
                write("你的法力提高了! \n");
		break;
		default: write("但是什么事也没有发生.\n");
	}
	return 1;
}
