inherit ITEM;

void create()
{
        set_name("摧心掌" , ({ "cuixin-zhang" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是青城祖传的摧心掌法秘芨.\n");
        set("skill", ([
                "name":                 "cuixin-zhang",      
                "exp_required": 30000,       
                "sen_cost":             30,
                "difficulty":   30,
                "base_skill":30,
                "max_skill":    100     
        ]) );
}
      
