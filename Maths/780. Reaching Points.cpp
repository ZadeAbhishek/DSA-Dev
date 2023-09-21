// top down approch but gives stack overflow 
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
       if(sx == tx && sy == ty) return true;

       if(sx>tx || sy > ty) return false;

       return (reachingPoints(sx+sy,sy,tx,ty)||reachingPoints(sx,sx+sy,tx,ty));
    }
};

// bottom down approch

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
     
     while(sx < tx && sy < ty){
         if(tx < ty) ty %= tx; // we can you minus also here inseead of mode
         else tx %= ty;
     }
     // while loop we will reach at some point near start point 

     // now we just need to check can we reach there 


     if(sx == tx && sy <=ty && (ty - sy)%sx == 0) return true;

     return (sy == ty && sx <= tx && (tx - sx)%sy == 0);
    }
};
// why (ty-sy)%sx == 0?
// since
// sy will translate to ty only by (sx+sy), if they translate then (sx, sy+k*sx) = ty for some k
// sy+k*sx = ty => (ty-sy) / sx = k.
// Since sx,sy,tx,ty are all integer, then k has to be a integer which means, there must be a integer k that help us to reach ty. Which makes reminder to be 0
// Hence
// (ty-sy) % sx == 0
// Complexity : O(log(n)) where n = Max(tx,ty)