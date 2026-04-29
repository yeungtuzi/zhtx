inherit ITEM;

void create()
{
        set_name("轻功入门" , ({ "dodge book","book" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍纵跃躲闪之术的入门书\n");
        set("value", 100);
        set("skill", ([
                "name":                 "dodge",      
                "exp_required": 5000,       
                "sen_cost":             30,
                "difficulty":   15,  
                "max_skill":    60,     
        ]) );
}
      
