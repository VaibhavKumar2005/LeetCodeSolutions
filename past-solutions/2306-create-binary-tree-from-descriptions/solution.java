/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {

        HashMap<Integer, TreeNode> nodeMap = new HashMap<>();
        HashSet<Integer> children = new HashSet<>();

        for (int[] description : descriptions) {

            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if (!nodeMap.containsKey(parent)) {
                nodeMap.put(parent, new TreeNode(parent));
            }

            if (!nodeMap.containsKey(child)) {
                nodeMap.put(child, new TreeNode(child));
            }

            TreeNode parentNode = nodeMap.get(parent);
            TreeNode childNode = nodeMap.get(child);

            if (isLeft == 1) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }

            children.add(child);
        }

        for (int value : nodeMap.keySet()) {
            if (!children.contains(value)) {
                return nodeMap.get(value);
            }
        }

        return null;
    }
}
